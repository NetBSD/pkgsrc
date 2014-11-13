# $NetBSD: packlist.mk,v 1.19 2014/11/13 17:48:59 tron Exp $
#
# This Makefile fragment is intended to be included by packages that
# create packlist files.  This file is automatically included by
# perl5/module.mk, so it is typically not necessary to include this
# file.
#
# The following variables should be set prior to including this file:
#
# PERL5_USE_PACKLIST
#	When set to "yes" (the default), automatically generates the
#	PLIST for the pkgsrc package from the Perl packlist.
#
# PERL5_PACKLIST_DIR	"install*arch" directory under which packlist
#			files are installed; defaults to
#			${PERL5_INSTALLVENDORARCH}.
#
# PERL5_PACKLIST	list of packlist files relative to
#			${PERL5_PACKLIST_DIR}.

.if !defined(_PERL5_PACKLIST_MK)
_PERL5_PACKLIST_MK=	# defined

.include "../../mk/bsd.prefs.mk"

PERL5_USE_PACKLIST?=	yes
.if !empty(PERL5_USE_PACKLIST:M[Yy][Ee][Ss])
# XXX: still experimental, but many packages already work
#PERL5_PACKLIST?=	auto/${DISTNAME:C/-[0-9].*$//:C,-,/,g}/.packlist
.endif

PERL5_PACKLIST_DESTDIR?=	yes

.if defined(PERL5_PACKLIST)
PERL5_PACKLIST_DIR?=	${PERL5_INSTALLVENDORARCH}
_PERL5_REAL_PACKLIST=	${PERL5_PACKLIST:S/^/${PERL5_PACKLIST_DIR}\//}
_PERL5_PACKLIST=	${_PERL5_REAL_PACKLIST:S/^/${DESTDIR}/}
.endif

###########################################################################
###
### INSTALL/DEINSTALL scripts to manage symlinks
###

INSTALL_TEMPLATES+=	${.CURDIR}/../../lang/perl5/files/install.tmpl
DEINSTALL_TEMPLATES+=	${.CURDIR}/../../lang/perl5/files/deinstall.tmpl
FILES_SUBST+=		PERL5_COMMENT=
FILES_SUBST+=		PERL5_PACKLIST=${_PERL5_REAL_PACKLIST:Q}


###########################################################################
###
### Packlist -> PLIST generation
###

# Generate the PLIST from the files listed in PERL5_PACKLIST.
.if defined(_PERL5_PACKLIST)
PERL5_PLIST_COMMENT_CMD= \
	{ ${ECHO} "@comment The following lines are automatically generated"; \
	  ${ECHO} "@comment from the installed .packlist files."; }
PERL5_PLIST_FILES_CMD= \
	{ ${CAT} ${_PERL5_PACKLIST}; for f in ${_PERL5_REAL_PACKLIST}; do ${TEST} ! -f "${DESTDIR}$$f" || ${ECHO} "$$f"; done; } \
	| ${SED} -e "s,[ 	].*,," -e "s,/\\./,/,g" -e "s,${PREFIX}/,," \
	| ${SORT} -u
PERL5_GENERATE_PLIST=	${PERL5_PLIST_COMMENT_CMD}; \
			${PERL5_PLIST_FILES_CMD};
GENERATE_PLIST+=	${PERL5_GENERATE_PLIST}
.endif

###########################################################################
###
### Packlist DESTDIR handling -- strip off the DESTDIR from each entry.
###

.if !empty(PERL5_PACKLIST_DESTDIR:M[Yy][Ee][Ss])
_PERL5_PACKLIST_AWK_STRIP_DESTDIR=					\
	BEGIN { destdir = "${DESTDIR}"; 				\
		gsub(/\/\//, "/", destdir);				\
		len_destdir = length(destdir); }			\
	{ if (index($$1, destdir) == 1) 				\
		$$1 = substr($$1, len_destdir + 1) }
.else
_PERL5_PACKLIST_AWK_STRIP_DESTDIR=
.endif

###########################################################################
###
### Packlist MANZ handling -- modify the .packlist so that it properly
### records either compressed or uncompressed manpages depending on
### how pkgsrc modifies them after installation.
###

_PERL5_PACKLIST_MANPAGE_RE=	\
  ^(\/[^ \/]*)+\/(man[1-9ln]\/[^ \/]*\.[1-9ln]|cat[1-9ln]\/[^ \/]*\.[0-9])$$

_PERL5_PACKLIST_AWK_STRIP_MANZ=						\
	/${_PERL5_PACKLIST_MANPAGE_RE}\.gz/				\
		{ $$1 = substr($$1, 1, length($$1) - 3); }

_PERL5_PACKLIST_AWK_ADD_MANZ.no=	# empty
_PERL5_PACKLIST_AWK_ADD_MANZ.yes=					\
	/${_PERL5_PACKLIST_MANPAGE_RE}/	{ $$1 = $$1 ".gz"; }

.if defined(_PERL5_PACKLIST)
post-install: perl-packlist
.endif

.PHONY: perl-packlist
perl-packlist:
	${RUN}								\
	${TEST} -n ${_PERL5_PACKLIST:Q}"" || exit 0;			\
	for file in ${_PERL5_PACKLIST}; do				\
		if ${TEST} ! -f "$$file"; then				\
			${ECHO} 1>&2 "Perl packlist $$file is missing."; \
			exit 1;						\
		fi;							\
		${AWK} '${_PERL5_PACKLIST_AWK_STRIP_DESTDIR}		\
			${_PERL5_PACKLIST_AWK_STRIP_MANZ}		\
			${_PERL5_PACKLIST_AWK_ADD_MANZ.${_MANZ}}	\
			{ print $$0 }'					\
			$$file > $$file.new;				\
		${MV} -f $$file.new $$file;				\
	done

.endif	# _PERL5_PACKLIST_MK
