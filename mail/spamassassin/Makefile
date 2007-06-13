# $NetBSD: Makefile,v 1.79.2.1 2007/06/13 08:05:04 ghen Exp $

DISTNAME=	Mail-SpamAssassin-3.1.9
PKGNAME=	spamassassin-3.1.9
SVR4_PKGNAME=	sa
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_APACHE:=spamassassin/source/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://spamassassin.apache.org/
COMMENT=	Mail filter to identify spam

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	p5-Net-DNS>=0.34:../../net/p5-Net-DNS
DEPENDS+=	p5-HTML-Parser>=3.31:../../www/p5-HTML-Parser
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	{p5-MIME-Base64>=2.11,perl>=5.8.0}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Archive-Tar>=1.23:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-IO-Zlib>=1.04:../../devel/p5-IO-Zlib

USE_TOOLS+=	perl

.if (${OPSYS} != "NetBSD") && (${OPSYS} != "DragonFly")
DEPENDS+=	p5-DB_File-[0-9]*:../../databases/p5-DB_File
.endif

CONFLICTS=		p5-Mail-SpamAssassin-[1-9]*

WRKSRC=			${WRKDIR}/${DISTNAME}

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
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_DIRS=		${WRKSRC}/spamc
BUILD_DIRS=		${WRKSRC}
PERL5_CONFIGURE=	NO # we need the default "do-configure" target
PERL5_CONFIGURE_DIRS=	${WRKSRC}

# test t/meta needs this
REPLACE_PERL+=		masses/parse-rules-for-masses

MAKE_PARAMS+=		CONTACT_ADDRESS=${SPAMASSASSIN_CONTACT_ADDRESS:Q}
MAKE_PARAMS+=		DEFRULESDIR="${RULESDIR}"
MAKE_PARAMS+=		LOCALRULESDIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		LOCALSTATEDIR="${VARBASE}/spamassassin"
MAKE_PARAMS+=		PERL_BIN="${PERL5}"
MAKE_PARAMS+=		SYSCONFDIR="${PKG_SYSCONFDIR}"

RCD_SCRIPTS=		spamd
RCD_SCRIPT_SRC.spamd=	${WRKSRC}/spamd/netbsd-rc-script.sh

EG_SUBDIR=		share/examples/spamassassin
EGDIR=			${PREFIX}/${EG_SUBDIR}
DOC_SUBDIR=		share/doc/spamassassin
DOCDIR=			${PREFIX}/${DOC_SUBDIR}
RULE_SUBDIR=		share/spamassassin
RULESDIR=		${PREFIX}/${RULE_SUBDIR}

PRE_FILES=		init.pre v310.pre v312.pre
.for p in ${PRE_FILES}
CONF_FILES+=		${EGDIR}/${p}  ${PKG_SYSCONFDIR}/${p}
.endfor
CONF_FILES+=		${EGDIR}/local.cf  ${PKG_SYSCONFDIR}/local.cf	\
			${RULESDIR}/user_prefs.template		\
		 	  ${PKG_SYSCONFDIR}/user_prefs.template

INSTALLATION_DIRS+=	${EG_SUBDIR} ${DOC_SUBDIR} ${DOC_SUBDIR}/spamc\
			${DOC_SUBDIR}/spamd ${RULE_SUBDIR}

OWN_DIRS+=		${VARBASE}/spamassassin
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/sa-update-keys ${SHAREOWN} ${SHAREGRP} 0700

SUBST_CLASSES+=		sa2
SUBST_STAGE.sa2=	pre-configure
SUBST_FILES.sa2=	README spamd/spamd.raw
SUBST_SED.sa2=		-e s!@@PREFIX@@!${PREFIX}!g
SUBST_SED.sa2+=		-e s!@PKG_SYSCONFDIR@!${PKG_SYSCONFDIR}!g

SUBST_CLASSES+=		sa3
SUBST_STAGE.sa3=	pre-configure
SUBST_FILES.sa3=	INSTALL UPGRADE USAGE ldap/README		\
			spamc/README.qmail				\
			lib/Mail/SpamAssassin/Conf.pm			\
			lib/Mail/SpamAssassin/Plugin/Test.pm		\
			spamd/README spamd/README.vpopmail sql/README	\
			sql/README.awl sa-update.raw
SUBST_SED.sa3=		-e s!/usr/share!${PREFIX}/share!g
SUBST_SED.sa3+=		-e s!/usr/bin!${PREFIX}/bin!g
SUBST_SED.sa3+=		-e s!/usr/local/bin!${PREFIX}/bin!g
SUBST_SED.sa3+=		-e s!/usr/lib!${PREFIX}/lib!g
SUBST_SED.sa3+=		-e s!/etc/mail/spamassassin!${PKG_SYSCONFDIR}!g

.if (${OPSYS} == "NetBSD") || (${OPSYS} == "DragonFly")
#  the 'spamd' RCD_SCRIPT behaves differently if we run NetBSD 1.6 or later
.  if (${OPSYS} == "NetBSD") && !empty(OS_VERSION:M1.[0-5]*)
INTERPRETER_SUPPORT=	NO
.  else
INTERPRETER_SUPPORT=	YES
.  endif
.endif

# These variables are substituted in netbsd-rc-script.sh.
FILES_SUBST+=		INTERPRETER_SUPPORT=${INTERPRETER_SUPPORT:Q}
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
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
	@${ECHO} "${DOC_SUBDIR}/${f}" >> ${PLIST_ADD}
.endfor
.for f in STATISTICS-set0.txt STATISTICS-set1.txt STATISTICS-set2.txt	\
	  STATISTICS-set3.txt
	@${INSTALL_DATA} ${WRKSRC}/rules/${f} ${DESTDIR}${DOCDIR}
	@${ECHO} "${DOC_SUBDIR}/${f}" >> ${PLIST_ADD}
.endfor
.for dir in masses sql ldap tools
	@cd ${WRKSRC};							\
	for d in `${FIND} ${dir} -type d -print`; do			\
		${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/$$d;			\
	done;								\
	for f in `${FIND} ${dir} -type f -print`; do			\
		if ${TEST} -x $$f ; then				\
			${SED} -e "1s,#!.*/bin/perl,#!${PERL5}," < $$f	\
				> $${f}.fixed &&			\
			${MV} $${f}.fixed $$f &&			\
			${CHMOD} +x $$f &&				\
			${INSTALL_SCRIPT} $$f ${DESTDIR}${DOCDIR}/$$f;		\
		else							\
			${INSTALL_DATA} $$f ${DESTDIR}${DOCDIR}/$$f;		\
		fi;							\
		${ECHO} "${DOC_SUBDIR}/$$f" >> ${PLIST_ADD};		\
	done;								\
	{ for d in `${FIND} ${dir} -type d -print`; do			\
		${ECHO} "@dirrm ${DOC_SUBDIR}/$$d";			\
	done; } | ${SORT} -r >> ${PLIST_ADD};
.endfor
	@cd ${WRKSRC}/rules;						\
	for f in [0-9]*.cf; do						\
		${ECHO} "${RULE_SUBDIR}/$$f" >> ${PLIST_ADD};		\
	done;								\
	for f in ${PRE_FILES}; do					\
		${INSTALL_DATA} $$f ${DESTDIR}${EGDIR} &&				\
		${ECHO} ${EG_SUBDIR}/$$f >> ${PLIST_ADD};		\
	done
	@# examples are in the static PLIST
	@${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${DESTDIR}${EGDIR}
	@${INSTALL_DATA} ${WRKSRC}/rules/local.cf ${DESTDIR}${EGDIR}
	@${INSTALL_DATA} ${FILESDIR}/netbsd_lists.cf ${DESTDIR}${EGDIR}
	@${CHOWN} ${SHAREOWN} ${DESTDIR}${RULESDIR}/*
	@${CHGRP} ${SHAREGRP} ${DESTDIR}${RULESDIR}/*
	@${CHMOD} a=r ${DESTDIR}${RULESDIR}/*
	@{ for d in ${INSTALLATION_DIRS}; do				\
		${ECHO} "@dirrm $$d";					\
	done; } | ${SORT} -r >> ${PLIST_ADD};

# make sure we install the patched version of init.pre but can run the
# tests with the original file
pre-patch:
	@${CP} ${WRKSRC}/rules/init.pre ${WRKDIR}/init.pre.notpatched

post-patch:
	@${CP} ${WRKSRC}/rules/init.pre ${WRKDIR}/init.pre.patched

pre-test:
	@${CP} ${WRKDIR}/init.pre.notpatched ${WRKSRC}/rules/init.pre

post-test:
	@${CP} ${WRKDIR}/init.pre.patched ${WRKSRC}/rules/init.pre

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
