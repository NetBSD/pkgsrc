# $NetBSD: Makefile,v 1.135 2019/08/11 13:21:42 wiz Exp $

DISTNAME=	Mail-SpamAssassin-3.4.2
PKGNAME=	spamassassin-3.4.2
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_APACHE:=spamassassin/source/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${RULESARCHIVE}
#DISTFILES+=	${RULESARCHIVEASC}
#DISTFILES+=	${RULESARCHIVESHA}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spamassassin.apache.org/
COMMENT=	Mail filter to identify spam
LICENSE=	apache-2.0

.include "../../mk/bsd.prefs.mk"

SMF_METHODS=	spamassassin

RULESARCHIVE=	Mail-SpamAssassin-rules-3.4.2.r1840640.tgz
#RULESARCHIVEASC=${RULESARCHIVE}.asc
#RULESARCHIVESHA=${RULESARCHIVE}.sha1
FILES_SUBST+=	RULESARCHIVE=${RULESDIR}/${RULESARCHIVE}
PLIST_SUBST+=	RULESARCHIVE=${RULESARCHIVE:Q}
#PLIST_SUBST+=	RULESARCHIVEASC=${RULESARCHIVEASC:Q}
#PLIST_SUBST+=	RULESARCHIVESHA=${RULESARCHIVESHA:Q}

#DEPENDS+=	{perl>=5.9.3,p5-Archive-Tar>=1.23}:../../archivers/p5-Archive-Tar
#DEPENDS+=	{perl>=5,p5-DB_File-[0-9]*}:../../databases/p5-DB_File
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-HTML-Parser>=3.43:../../www/p5-HTML-Parser
#DEPENDS+=	{perl>=5.9.3,p5-IO-Compress-[0-9]*}:../../devel/p5-IO-Compress # Compress::Zlib>=0
#DEPENDS+=	{perl>=5.9.3,p5-IO-Zlib>=1.04}:../../devel/p5-IO-Zlib
DEPENDS+=	p5-Mail-DKIM>=0.40:../../mail/p5-Mail-DKIM
DEPENDS+=	p5-Mail-SPF-[0-9]*:../../mail/p5-Mail-SPF
#DEPENDS+=	{p5-MIME-Base64>=2.11,perl>=5.8.0}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-NetAddr-IP>=4.007:../../net/p5-NetAddr-IP
DEPENDS+=	p5-Net-DNS>=1.01:../../net/p5-Net-DNS
#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	re2c>=0.13.6:../../devel/re2c

USE_TOOLS+=	perl

CONFLICTS=		p5-Mail-SpamAssassin-[0-9]*

WRKSRC=			${WRKDIR}/${DISTNAME}

PKG_SYSCONFSUBDIR=	spamassassin

# Set contact address (e-mail, URL, ...) for use in spam report messages
# See "perldoc Mail::SpamAssassin::Conf" for option "report_contact"
SPAMASSASSIN_CONTACT_ADDRESS?=	postmaster

.include "options.mk"

BUILD_DEFS+=		SPAMASSASSIN_CONTACT_ADDRESS
BUILD_DEFS+=		VARBASE

DYNAMIC_PLIST=		${WRKSRC}/.PLIST_ADD
PLIST_SRC=		${PKGDIR}/PLIST ${DYNAMIC_PLIST}
PERL5_PACKLIST=		auto/Mail/SpamAssassin/.packlist

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_DIRS=		spamc
# Fix openssl detection. These methods are deprecated and removed, but
# still the configure scripts looks for them.
CONFIGURE_ENV+=		ac_cv_lib_ssl_SSL_CTX_free=yes
CONFIGURE_ENV+=		ac_cv_lib_crypto_CRYPTO_lock=yes
BUILD_DIRS=		.  # build at the top-level directory, not in "spamc"
PERL5_CONFIGURE=	NO # we need the default "do-configure" target
PERL5_CONFIGURE_DIRS=	${WRKSRC}

# test t/meta needs this
REPLACE_PERL+=		build/parse-rules-for-masses
REPLACE_PERL+=		sa-update.raw

MAKE_PARAMS+=		CONTACT_ADDRESS=${SPAMASSASSIN_CONTACT_ADDRESS:Q}
MAKE_PARAMS+=		DEFRULESDIR="${RULESDIR}"
MAKE_PARAMS+=		LOCALRULESDIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		LOCALSTATEDIR="${VARBASE}/spamassassin"
MAKE_PARAMS+=		PERL_BIN="${PERL5}"
MAKE_PARAMS+=		PERL_WARN=yes
MAKE_PARAMS+=		PERL_TAINT=yes
MAKE_PARAMS+=		SYSCONFDIR="${PKG_SYSCONFDIR}"

TEST_MAKE_FLAGS=	HOME=${HOME}  # for test t/razor2.t

RCD_SCRIPTS=		spamd
RCD_SCRIPT_SRC.spamd=	${WRKSRC}/spamd/netbsd-rc-script.sh

EG_SUBDIR=		share/examples/spamassassin
EGDIR=			${PREFIX}/${EG_SUBDIR}
DOC_SUBDIR=		share/doc/spamassassin
DOCDIR=			${PREFIX}/${DOC_SUBDIR}
RULE_SUBDIR=		share/spamassassin
RULESDIR=		${PREFIX}/${RULE_SUBDIR}

PRE_FILES=		init.pre v310.pre v312.pre v320.pre v330.pre v340.pre
.for p in ${PRE_FILES}
CONF_FILES+=		${EGDIR}/${p}  ${PKG_SYSCONFDIR}/${p}
.endfor
CONF_FILES+=		${EGDIR}/local.cf  ${PKG_SYSCONFDIR}/local.cf	\
			${RULESDIR}/user_prefs.template			\
			  ${PKG_SYSCONFDIR}/user_prefs.template

SA_INSTALLDIRS=		${EG_SUBDIR} ${DOC_SUBDIR} ${DOC_SUBDIR}/ldap
SA_INSTALLDIRS+=	${DOC_SUBDIR}/rules ${DOC_SUBDIR}/spamc
SA_INSTALLDIRS+=	${DOC_SUBDIR}/spamd ${DOC_SUBDIR}/sql ${RULE_SUBDIR}

SA_DOCFILES=		INSTALL LICENSE README TRADEMARK UPGRADE USAGE NOTICE
SA_DOCFILES+=		CREDITS PACKAGING Changes
SA_DOCFILES+=		ldap/README ldap/README.testing ldap/sa_test.ldif
SA_DOCFILES+=		rules/sa-update-pubkey.txt
SA_DOCFILES+=		spamc/README.qmail
SA_DOCFILES+=		sample-nonspam.txt sample-spam.txt
SA_DOCFILES+=		spamd/README spamd/README.vpopmail
SA_DOCFILES+=		sql/README sql/README.awl sql/README.bayes
SA_DOCFILES+=		sql/awl_mysql.sql sql/awl_pg.sql sql/bayes_mysql.sql
SA_DOCFILES+=		sql/bayes_pg.sql sql/userpref_mysql.sql
SA_DOCFILES+=		sql/userpref_pg.sql

OWN_DIRS+=		${VARBASE}/spamassassin
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/sa-update-keys ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

SUBST_CLASSES+=		sa2
SUBST_MESSAGE.sa2=	Setting correct paths for pkgsrc (part 1)
SUBST_STAGE.sa2=	pre-configure
SUBST_FILES.sa2=	README spamd/spamd.raw
SUBST_SED.sa2=		-e s!@@PREFIX@@!${PREFIX}!g
SUBST_VARS.sa2=		PKG_SYSCONFDIR
SUBST_VARS.sa2+=	VARBASE

SUBST_CLASSES+=		sa3
SUBST_MESSAGE.sa3=	Setting correct paths for pkgsrc (part 2)
SUBST_STAGE.sa3=	pre-configure
SUBST_FILES.sa3=	INSTALL UPGRADE USAGE ldap/README
SUBST_FILES.sa3+=	spamc/README.qmail spamc/spamc.pod
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
FILES_SUBST+=		INTERPRETER_SUPPORT=${INTERPRETER_SUPPORT}
FILES_SUBST+=		OPSYS=${OPSYS}

INSTALLATION_DIRS+=	${SA_INSTALLDIRS}

# Configure the programe that "sa-update" uses for fetching files
.if defined(TOOLS_PLATFORM.curl)
SA_UPDATE_FETCH_PROG=	curl
SA_UPDATE_FETCH_CMD=	${TOOLS_PLATFORM.curl}
.elif defined(TOOLS_PLATFORM.fetch)
SA_UPDATE_FETCH_PROG=	fetch
SA_UPDATE_FETCH_CMD=	${TOOLS_PLATFORM.fetch}
.else
DEPENDS+=	wget-[0-9]*:../../net/wget

SA_UPDATE_FETCH_PROG=	wget
SA_UPDATE_FETCH_CMD=	${PREFIX}/bin/wget
.endif
SUBST_CLASSES+=		fetch
SUBST_STAGE.fetch=	pre-configure
SUBST_FILES.fetch=	sa-update.raw
SUBST_VARS.fetch=	SA_UPDATE_FETCH_CMD SA_UPDATE_FETCH_PROG

pre-configure: perl5-configure
	# GNU configure needs version.h -> create it
	cd ${WRKSRC}/spamc && ${PERL5} ./version.h.pl
	# values in 'config' will be set via the SUBST framework in options.mk
	${CP} ${WRKSRC}/t/config.dist ${WRKSRC}/t/config

post-install:
	${TEST} -r ${DYNAMIC_PLIST} && ${RM} ${DYNAMIC_PLIST} ; :
.for f in ${SA_DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
	${ECHO} "${DOC_SUBDIR}/${f}" >> ${DYNAMIC_PLIST}
.endfor

	set -e ; cd ${WRKSRC}/rules;					\
	for f in ${PRE_FILES}; do					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${EGDIR} &&		\
		${ECHO} "${EG_SUBDIR}/$$f" >> ${DYNAMIC_PLIST};		\
	done
	# examples are in the static PLIST
	${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rules/local.cf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/netbsd_lists.cf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${RULESARCHIVE}	\
		${DESTDIR}${RULESDIR}
#	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${RULESARCHIVEASC}	\
#		${DESTDIR}${RULESDIR}
#	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${RULESARCHIVESHA}	\
#		${DESTDIR}${RULESDIR}

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
