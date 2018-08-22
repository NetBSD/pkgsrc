# $NetBSD: Makefile,v 1.48 2018/08/22 09:43:28 wiz Exp $

DISTNAME=	bugzilla-5.0.3
PKGREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=webtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bugzilla.org/
COMMENT=	Web based bug tracking system
LICENSE=	mpl-2.0

# mod_perl
DEPENDS+=	ap2[0-9]-perl-[0-9]*:../../www/ap2-perl
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=	p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-TimeZone-[0-9]*:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Email-Sender-[0-9]*:../../mail/p5-Email-Sender
DEPENDS+=	p5-Email-MIME-[0-9]*:../../mail/p5-Email-MIME
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Math-Random-ISAAC-[0-9]*:../../math/p5-Math-Random-ISAAC
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS

DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-Chart-[0-9]*:../../graphics/p5-Chart
DEPENDS+=	libwww-[0-9]*:../../www/libwww
DEPENDS+=	p5-Template-GD-[0-9]*:../../graphics/p5-Template-GD
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil
DEPENDS+=	p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig
DEPENDS+=	p5-PatchReader-[0-9]*:../../devel/p5-PatchReader
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap
DEPENDS+=	p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL
DEPENDS+=	p5-Net-SMTP-SSL-[0-9]*:../../mail/p5-Net-SMTP-SSL
DEPENDS+=	p5-RadiusPerl-[0-9]*:../../net/p5-RadiusPerl
DEPENDS+=	p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
DEPENDS+=	p5-XMLRPC-Lite-[0-9]*:../../net/p5-XMLRPC-Lite
DEPENDS+=	p5-JSON-RPC-[0-9]*:../../www/p5-JSON-RPC
DEPENDS+=	p5-Test-Taint-[0-9]*:../../devel/p5-Test-Taint
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Scrubber-[0-9]*:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-Encode-[0-9]*:../../textproc/p5-Encode
DEPENDS+=	p5-Encode-Detect-[0-9]*:../../textproc/p5-Encode-Detect
DEPENDS+=	p5-Email-Reply-[0-9]*:../../mail/p5-Email-Reply
DEPENDS+=	p5-HTML-FormatText-WithLinks-[0-9]*:../../textproc/p5-HTML-FormatText-WithLinks
DEPENDS+=	p5-TheSchwartz-[0-9]*:../../devel/p5-TheSchwartz
DEPENDS+=	p5-Daemon-Generic-[0-9]*:../../sysutils/p5-Daemon-Generic
DEPENDS+=	p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-Cache-Memcached-[0-9]*:../../devel/p5-Cache-Memcached
DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which

# DEPENDS+=	p5-DBI>=1.41:../../databases/p5-DBI
# DEPENDS+=	p5-Template-Toolkit>=2.15:../../www/p5-Template-Toolkit
# DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
# DEPENDS+=	p5-Email-Send>=2.00:../../mail/p5-Email-Send
# DEPENDS+=	p5-Email-MIME>=1.903:../../mail/p5-Email-MIME

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

USE_TOOLS+=	pax perl:run
NO_BUILD=	YES

BZ_WEB_GROUP?=	${APACHE_GROUP}
SENDMAIL?=	/usr/sbin/sendmail
CVS?=		/usr/bin/cvs

BUILD_DEFS+=	SENDMAIL CVS APACHE_USER APACHE_GROUP
PERL5_REQD+=	5.8.1

PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	BZ_WEB_GROUP APACHE_GROUP

MESSAGE_SUBST+=	BZDIR=${BZDIR} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

BZDIR=			${PREFIX}/share/bugzilla
EGDIR=			${PREFIX}/share/examples/bugzilla
DOCDIR=			${PREFIX}/share/doc/bugzilla
CONF_FILES=		${EGDIR}/bugzilla.conf ${PKG_SYSCONFDIR}/bugzilla.conf
CONF_FILES_PERMS=	${EGDIR}/localconfig ${BZDIR}/localconfig \
			${APACHE_USER} ${SHAREGRP} 0400

REPLACE_PERL+=		*.pl *.cgi docs/makedocs.pl

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_MESSAGE.conf=	Fixing configuration files.
SUBST_FILES.conf=	bugzilla.conf localconfig Bugzilla/BugMail.pm
SUBST_SED.conf=		-e "s|@BZ_WEB_GROUP@|${BZ_WEB_GROUP}|g"
SUBST_SED.conf+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.conf+=	-e "s|@BZDIR@|${BZDIR}|g"
SUBST_SED.conf+=	-e "s|@CVS@|${CVS}|g"
SUBST_SED.conf+=	-e "s|@DBDRIVER@|${DBDRIVER}|g"
SUBST_SED.conf+=	-e "s|/usr/lib/sendmail|${SENDMAIL}|g"

SUBST_CLASSES+=		diff
SUBST_STAGE.diff=	post-configure
SUBST_MESSAGE.diff=	Fixing diff path used for Patch Viewer (Ignore depending on OS)
SUBST_FILES.diff=	localconfig
SUBST_SED.diff=		-e "s|\$$diffpath = .*|\$$diffpath = \'${DIFF:C,/[^/]+$,,}\';|"

INSTALLATION_DIRS+=	${DOCDIR} ${DOCDIR}/en ${EGDIR} ${BZDIR} ${BZDIR}/Bugzilla
INSTALLATION_DIRS+=	${BZDIR}/js ${BZDIR}/lib ${BZDIR}/template ${BZDIR}/skins
INSTALLATION_DIRS+=	${BZDIR}/docs ${BZDIR}/docs/en ${BZDIR}/docs/en/html
INSTALLATION_DIRS+=	${BZDIR}/images ${BZDIR}/docs/en/html/api
INSTALLATION_DIRS+=	${BZDIR}/docs/en/html/api/Bugzilla
.for i in data contrib t xt template lib graphs skins
INSTALLATION_DIRS+=	${BZDIR}/${i}
.endfor

FILES_SUBST+=   WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
                BZDIR=${BZDIR}

do-configure:
	cd ${WRKSRC} && ./checksetup.pl

post-extract:
	${CP} ${FILESDIR}/bugzilla.conf	${WRKSRC}
	${CP} ${FILESDIR}/localconfig	${WRKSRC}

do-install:

.for i in ${BZDIR} ${EGDIR} ${DOCDIR} ${BZDIR}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${i}
.endfor
	(cd ${WRKSRC}					    ;\
	pax -rw -pmp docs		${DESTDIR}${BZDIR} ;\
	${INSTALL_SCRIPT} *.cgi *.pl	${DESTDIR}${BZDIR}  ;\
	${INSTALL_SCRIPT} robots.txt	${DESTDIR}${BZDIR}  ;\
	${INSTALL_DATA} Bugzilla.pm	${DESTDIR}${BZDIR}  ;\
	${INSTALL_DATA} README		${DESTDIR}${DOCDIR} ;\
	${INSTALL_DATA} localconfig	${DESTDIR}${EGDIR}  ;\
	${INSTALL_DATA} bugzilla.conf	${DESTDIR}${EGDIR}  ;\
	${INSTALL_DATA} images/*.png	${DESTDIR}${BZDIR}/images  ;\
	${INSTALL_DATA} images/favicon.ico	${DESTDIR}${BZDIR} ;\
	pax -rw -pmp Bugzilla		${DESTDIR}${BZDIR}  ;\
	pax -rw -pmp js			${DESTDIR}${BZDIR}  ;\
	pax -rw -pmp template		${DESTDIR}${BZDIR} ;\
	)
	${RM} ${DESTDIR}${BZDIR}/Bugzilla/Install/Filesystem.pm.orig

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
