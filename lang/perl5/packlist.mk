# $NetBSD: packlist.mk,v 1.1 2005/10/19 04:40:23 jlam Exp $
#
# This Makefile fragment is intended to be included by packages that
# create packlist files.  This file is automatically included by
# perl5/module.mk, so it is typically not necessary to include this
# file.
#
# The following variables should be set prior to including this file:
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

.if defined(PERL5_PACKLIST)
PERL5_PACKLIST_DIR?=	${PERL5_INSTALLVENDORARCH}
_PERL5_PACKLIST=	${PERL5_PACKLIST:S/^/${PERL5_PACKLIST_DIR}\//}
.endif


###########################################################################
###
### INSTALL/DEINSTALL scripts to manage symlinks
###

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${.CURDIR}/../../lang/perl5/files/install.tmpl
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/../../lang/perl5/files/deinstall.tmpl
FILES_SUBST+=		PERL5_COMMENT=
FILES_SUBST+=		PERL5_PACKLIST=${_PERL5_PACKLIST:Q}


###########################################################################
###
### Packlist -> PLIST generation
###

# Generate the PLIST from the files listed in PERL5_PACKLIST.
.if defined(_PERL5_PACKLIST)
PERL5_PLIST_COMMENT= \
	{ ${ECHO} "@comment The following lines are automatically generated"; \
	  ${ECHO} "@comment from the installed .packlist files."; }
PERL5_PLIST_FILES= \
	{ ${CAT} ${_PERL5_PACKLIST}; for f in ${_PERL5_PACKLIST}; do ${TEST} ! -f "$$f" || ${ECHO} "$$f"; done; } \
	| ${SED} -e "s,[ 	].*,," -e "s,/\./,/,g" -e "s,${PREFIX}/,," \
	| ${SORT} -u
PERL5_PLIST_DIRS= \
	{ ${CAT} ${_PERL5_PACKLIST}; for f in ${_PERL5_PACKLIST}; do ${TEST} ! -f "$$f" || ${ECHO} "$$f"; done; } \
	| ${SED} -e "s,[ 	].*,," -e "s,/\./,/,g" -e "s,${PREFIX}/,," \
		-e "s,^,@unexec \${RMDIR} -p %D/," \
		-e "s,/[^/]*$$, 2>/dev/null || ${TRUE}," \
	| ${SORT} -ur
PERL5_GENERATE_PLIST=	${PERL5_PLIST_COMMENT}; \
			${PERL5_PLIST_FILES}; \
			${PERL5_PLIST_DIRS}
GENERATE_PLIST+=	${PERL5_GENERATE_PLIST};
.endif

.endif	# _PERL5_PACKLIST_MK
