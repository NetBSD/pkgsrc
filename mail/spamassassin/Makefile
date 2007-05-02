# $NetBSD: Makefile,v 1.80 2007/05/02 15:20:45 heinz Exp $

DISTNAME=	Mail-SpamAssassin-3.2.0
PKGNAME=	spamassassin-3.2.0
SVR4_PKGNAME=	sa
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_APACHE:=spamassassin/source/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://spamassassin.apache.org/
COMMENT=	Mail filter to identify spam

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
CONFIGURE_DIRS=		spamc
BUILD_DIRS=		.
PERL5_CONFIGURE=	NO # we need the default "do-configure" target
PERL5_CONFIGURE_DIRS=	${WRKSRC}

# test t/meta needs this
REPLACE_PERL+=		build/parse-rules-for-masses

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

PRE_FILES=		init.pre v310.pre v312.pre v320.pre
.for p in ${PRE_FILES}
CONF_FILES+=		${EGDIR}/${p}  ${PKG_SYSCONFDIR}/${p}
.endfor
CONF_FILES+=		${EGDIR}/local.cf  ${PKG_SYSCONFDIR}/local.cf	\
			${RULESDIR}/user_prefs.template		\
		 	  ${PKG_SYSCONFDIR}/user_prefs.template

SA_INSTALLDIRS=		${EG_SUBDIR} ${DOC_SUBDIR} ${DOC_SUBDIR}/ldap
SA_INSTALLDIRS+=	${DOC_SUBDIR}/rules ${DOC_SUBDIR}/spamc
SA_INSTALLDIRS+=	${DOC_SUBDIR}/spamd ${DOC_SUBDIR}/sql ${RULE_SUBDIR}

SA_DOCFILES=		INSTALL LICENSE README TRADEMARK UPGRADE USAGE NOTICE
SA_DOCFILES+=		CREDITS PACKAGING Changes
SA_DOCFILES+=		ldap/README ldap/README.testing ldap/sa_test.ldif
SA_DOCFILES+=		rules/STATISTICS-set0.txt rules/STATISTICS-set1.txt
SA_DOCFILES+=		rules/STATISTICS-set2.txt rules/STATISTICS-set3.txt
SA_DOCFILES+=		spamc/README.qmail
SA_DOCFILES+=		sample-nonspam.txt sample-spam.txt
SA_DOCFILES+=		spamd/README spamd/README.vpopmail
SA_DOCFILES+=		sql/README sql/README.awl sql/README.bayes
SA_DOCFILES+=		sql/awl_mysql.sql sql/awl_pg.sql sql/bayes_mysql.sql
SA_DOCFILES+=		sql/bayes_pg.sql sql/userpref_mysql.sql
SA_DOCFILES+=		sql/userpref_pg.sql

OWN_DIRS+=		${VARBASE}/spamassassin
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/sa-update-keys ${SHAREOWN} ${SHAREGRP} 0700

SUBST_CLASSES+=		sa2
SUBST_STAGE.sa2=	pre-configure
SUBST_FILES.sa2=	README spamd/spamd.raw
SUBST_SED.sa2=		-e s!@@PREFIX@@!${PREFIX}!g
SUBST_SED.sa2+=		-e s!@PKG_SYSCONFDIR@!${PKG_SYSCONFDIR}!g

SUBST_CLASSES+=		sa3
SUBST_STAGE.sa3=	pre-configure
SUBST_FILES.sa3=	INSTALL UPGRADE USAGE ldap/README
SUBST_FILES.sa3+=	spamc/README.qmail
SUBST_FILES.sa3+=	lib/Mail/SpamAssassin/Conf.pm
SUBST_FILES.sa3+=	lib/Mail/SpamAssassin/Plugin/Test.pm
SUBST_FILES.sa3+=	spamd/README spamd/README.vpopmail sql/README
SUBST_FILES.sa3+=	sql/README.awl sa-learn.raw sa-compile.raw sa-update.raw
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

pre-configure: perl5-configure
	# GNU configure needs version.h -> create it
	cd ${WRKSRC}/spamc && ${PERL5} ./version.h.pl
	# values will be set via the SUBST framework in options.mk
	${CP} ${WRKSRC}/t/config.dist ${WRKSRC}/t/config

post-install:
	${TEST} -r ${PLIST_ADD} && ${RM} ${PLIST_ADD} ; :
.for dir in ${SA_INSTALLDIRS}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${dir}
.endfor
.for f in ${SA_DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
	${ECHO} "${DOC_SUBDIR}/${f}" >> ${PLIST_ADD}
.endfor

	cd ${WRKSRC}/rules;						\
	for f in [0-9]*.cf; do						\
		${ECHO} "${RULE_SUBDIR}/$$f" >> ${PLIST_ADD};		\
	done;								\
	for f in ${PRE_FILES}; do					\
		${INSTALL_DATA} $$f ${DESTDIR}${EGDIR} &&		\
		${ECHO} ${EG_SUBDIR}/$$f >> ${PLIST_ADD};		\
	done
	# examples are in the static PLIST
	${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rules/local.cf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/netbsd_lists.cf ${DESTDIR}${EGDIR}
	{ for d in ${SA_INSTALLDIRS}; do				\
		${ECHO} "@dirrm $$d";					\
	done; } | ${SORT} -r >> ${PLIST_ADD};

# make sure we install the patched version of init.pre but can run the
# tests with the original file
pre-patch:
	${CP} ${WRKSRC}/rules/init.pre ${WRKDIR}/init.pre.notpatched

post-patch:
	${CP} ${WRKSRC}/rules/init.pre ${WRKDIR}/init.pre.patched

pre-test:
	${CP} ${WRKDIR}/init.pre.notpatched ${WRKSRC}/rules/init.pre

post-test:
	${CP} ${WRKDIR}/init.pre.patched ${WRKSRC}/rules/init.pre

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
