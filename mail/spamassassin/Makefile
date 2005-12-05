# $NetBSD: Makefile,v 1.65 2005/12/05 20:50:35 rillig Exp $

DISTNAME=	Mail-SpamAssassin-3.1.0
PKGNAME=	spamassassin-3.1.0
PKGREVISION=	2
SVR4_PKGNAME=	sa
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_APACHE:=spamassassin/source/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://spamassassin.apache.org/
COMMENT=	Mail filter to identify spam

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	p5-Net-DNS>=0.34:../../net/p5-Net-DNS
DEPENDS+=	p5-HTML-Parser>=3.31:../../www/p5-HTML-Parser
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	{p5-MIME-Base64>=2.11,perl{,-thread}>=5.8.0}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Archive-Tar-[0-9]*:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-IO-Zlib-[0-9]*:../../devel/p5-IO-Zlib

.if (${OPSYS} != "NetBSD") && (${OPSYS} != "DragonFly")
DEPENDS+=	p5-DB_File-[0-9]*:../../databases/p5-DB_File
.endif

CONFLICTS=		p5-Mail-SpamAssassin-[1-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_PKGINSTALL=		YES
PKG_SYSCONFSUBDIR=	spamassassin

# Set contact address (e-mail, URL, ...) for use in spam report messages
# See "perldoc Mail::SpamAssassin::Conf" for option "report_contact"
SPAMASSASSIN_CONTACT_ADDRESS?=	postmaster

.include "options.mk"

BUILD_DEFS+=		SPAMASSASSIN_CONTACT_ADDRESS

PLIST_ADD=		${WRKSRC}/.PLIST_ADD
PLIST_SRC=		${PKGDIR}/PLIST ${PLIST_ADD}
PERL5_PACKLIST=		auto/Mail/SpamAssassin/.packlist

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_DIRS=		${WRKSRC}/spamc
BUILD_DIRS=		${WRKSRC}
PERL5_CONFIGURE=	NO # we need the default "do-configure" target
PERL5_CONFIGURE_DIRS=	${WRKSRC}

# test t/meta needs this
REPLACE_PERL=		masses/parse-rules-for-masses

MAKE_PARAMS+=		CONTACT_ADDRESS=${SPAMASSASSIN_CONTACT_ADDRESS:Q}
MAKE_PARAMS+=		DEFRULESDIR="${_RULESDIR}"
MAKE_PARAMS+=		LOCALRULESDIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		PERL_BIN="${PERL5}"
MAKE_PARAMS+=		SYSCONFDIR="${PKG_SYSCONFDIR}"

RCD_SCRIPTS=		spamd
RCD_SCRIPT_SRC.spamd=	${WRKSRC}/spamd/netbsd-rc-script.sh

_EG_SUBDIR=		share/examples/spamassassin
_EGDIR=			${PREFIX}/${_EG_SUBDIR}
_DOC_SUBDIR=		share/doc/spamassassin
_DOCDIR=		${PREFIX}/${_DOC_SUBDIR}
_RULE_SUBDIR=		share/spamassassin
_RULESDIR=		${PREFIX}/${_RULE_SUBDIR}

CONF_FILES+=		${_EGDIR}/local.cf  ${PKG_SYSCONFDIR}/local.cf	\
			${_EGDIR}/init.pre  ${PKG_SYSCONFDIR}/init.pre	\
			${_EGDIR}/v310.pre  ${PKG_SYSCONFDIR}/v310.pre	\
			${_RULESDIR}/user_prefs.template		\
		 	  ${PKG_SYSCONFDIR}/user_prefs.template

INSTALLATION_DIRS+=	${_EG_SUBDIR} ${_DOC_SUBDIR} ${_DOC_SUBDIR}/spamc\
			${_DOC_SUBDIR}/spamd

SUBST_CLASSES+=		sa2 sa3

SUBST_STAGE.sa2=	pre-configure
SUBST_FILES.sa2=	README spamd/spamd.raw
SUBST_SED.sa2=		-e s!@@PREFIX@@!${PREFIX}!g			\
			-e s!@PKG_SYSCONFDIR@!${PKG_SYSCONFDIR}!g

SUBST_STAGE.sa3=	pre-configure
SUBST_FILES.sa3=	INSTALL UPGRADE USAGE ldap/README		\
			spamc/README.qmail				\
			lib/Mail/SpamAssassin/Conf.pm			\
			lib/Mail/SpamAssassin/Plugin/Test.pm		\
			spamd/README spamd/README.vpopmail sql/README	\
			sql/README.awl sa-update.raw
SUBST_SED.sa3=		-e s!/usr/share!${PREFIX}/share!g		\
			-e s!/usr/bin!${PREFIX}/bin!g			\
			-e s!/usr/local/bin!${PREFIX}/bin!g		\
			-e s!/usr/lib!${PREFIX}/lib!g			\
			-e s!/etc/mail/spamassassin!${PKG_SYSCONFDIR}!g

.if (${OPSYS} == "NetBSD") || (${OPSYS} == "DragonFly")
#  the 'spamd' RCD_SCRIPT behaves differently if we run NetBSD 1.6 or later
.  if (${OPSYS} == "NetBSD") && !empty(OS_VERSION:M1.[0-5]*)
_INTERPRETER_SUPPORT=	NO
.  else
_INTERPRETER_SUPPORT=	YES
.  endif
.endif

# These variables are substituted in netbsd-rc-script.sh.
FILES_SUBST+=		_INTERPRETER_SUPPORT=${_INTERPRETER_SUPPORT:Q}
FILES_SUBST+=		OPSYS=${OPSYS:Q}

post-extract:
	@# correct bad SA permissions
	@${CHMOD} a+x ${WRKSRC}/tools/convert_awl_dbm_to_sql

pre-configure: perl5-configure
	@# GNU configure needs version.h -> create it
	@cd ${WRKSRC}/spamc && ${PERL5} ./version.h.pl
	@# values will be set via the SUBST framework in options.mk
	@${CP} ${WRKSRC}/t/config.dist ${WRKSRC}/t/config

post-install:
	@${TEST} -r ${PLIST_ADD} && ${RM} ${PLIST_ADD} ; :
.for f in INSTALL LICENSE README TRADEMARK UPGRADE USAGE		\
		CREDITS PACKAGING STATUS BUGS Changes			\
		spamc/README.qmail					\
		sample-nonspam.txt sample-spam.txt spamd/README		\
		spamd/README.vpopmail
	@${INSTALL_DATA} ${WRKSRC}/${f} ${_DOCDIR}/${f}
	@${ECHO} "${_DOC_SUBDIR}/${f}" >> ${PLIST_ADD}
.endfor
.for f in STATISTICS-set0.txt STATISTICS-set1.txt STATISTICS-set2.txt	\
	  STATISTICS-set3.txt
	@${INSTALL_DATA} ${WRKSRC}/rules/${f} ${_DOCDIR}/
	@${ECHO} "${_DOC_SUBDIR}/${f}" >> ${PLIST_ADD}
.endfor
.for dir in masses sql ldap tools
	@cd ${WRKSRC};							\
	for d in `${FIND} ${dir} -type d -print`; do			\
		${INSTALL_DATA_DIR} ${_DOCDIR}/$$d;			\
	done;								\
	for f in `${FIND} ${dir} -type f -print`; do			\
		if ${TEST} -x $$f ; then				\
			${SED} -e "1s,#!.*/bin/perl,#!${PERL5}," < $$f	\
				> $${f}.fixed &&			\
			${MV} $${f}.fixed $$f &&			\
			${CHMOD} +x $$f &&				\
			${INSTALL_SCRIPT} $$f ${_DOCDIR}/$$f;		\
		else							\
			${INSTALL_DATA} $$f ${_DOCDIR}/$$f;		\
		fi;							\
		${ECHO} "${_DOC_SUBDIR}/$$f" >> ${PLIST_ADD};		\
	done;								\
	{ for d in `${FIND} ${dir} -type d -print`; do			\
		${ECHO} "@dirrm ${_DOC_SUBDIR}/$$d";			\
	done; } | ${SORT} -r >> ${PLIST_ADD};
.endfor
	@cd ${WRKSRC}/rules;						\
	for f in [0-9]*.cf; do						\
		${ECHO} "${_RULE_SUBDIR}/$$f" >> ${PLIST_ADD};		\
	done
	@${ECHO} "@dirrm ${_RULE_SUBDIR}" >> ${PLIST_ADD}
	@# examples are in the static PLIST
	@${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${_EGDIR}/
	@${INSTALL_DATA} ${WRKSRC}/rules/init.pre ${_EGDIR}/
	@${INSTALL_DATA} ${WRKSRC}/rules/v310.pre ${_EGDIR}/
	@${INSTALL_DATA} ${WRKSRC}/rules/local.cf ${_EGDIR}/
	@${INSTALL_DATA} ${FILESDIR}/netbsd_lists.cf ${_EGDIR}/
	@${CHOWN} ${SHAREOWN} ${_RULESDIR}/*
	@${CHGRP} ${SHAREGRP} ${_RULESDIR}/*
	@${CHMOD} a=r ${_RULESDIR}/*
	@{ for d in ${INSTALLATION_DIRS}; do				\
		${ECHO} "@dirrm $$d";					\
	done; } | ${SORT} -r >> ${PLIST_ADD};

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
