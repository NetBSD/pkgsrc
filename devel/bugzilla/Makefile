# $NetBSD: Makefile,v 1.38 2013/11/24 09:57:03 wiz Exp $

DISTNAME=	bugzilla-2.22.7
PKGREVISION=	3
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=webtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bugzilla.org/
COMMENT=	Web based bug tracking system

DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=	p5-CGI>=2.93:../../www/p5-CGI
DEPENDS+=	p5-DBI>=1.38:../../databases/p5-DBI
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp
DEPENDS+=	p5-Template-Toolkit>=2.10:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Tabs+Wrap>=2001.0131:../../textproc/p5-Text-Tabs+Wrap
#DEPENDS+=	p5-Storable-[0-9]*:../../devel/p5-Storable
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
DEPENDS+=	p5-MailTools>=1.74:../../mail/p5-MailTools
DEPENDS+=	p5-MIME-Base64>=3.01:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MIME-tools>=5.406:../../mail/p5-MIME-tools

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

USE_TOOLS+=	pax perl:run
NO_BUILD=	YES

BZ_WEB_GROUP?=	${APACHE_GROUP}
SENDMAIL?=	/usr/sbin/sendmail
CVS?=		/usr/bin/cvs

BUILD_DEFS+=	SENDMAIL CVS

PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	BZ_WEB_GROUP APACHE_GROUP

MESSAGE_SUBST+=	BZDIR=${BZDIR:Q} PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

BZDIR=		${PREFIX}/share/bugzilla
EGDIR=		${PREFIX}/share/examples/bugzilla
DOCDIR=		${PREFIX}/share/doc/bugzilla
CONF_FILES=	${EGDIR}/bugzilla.conf ${PKG_SYSCONFDIR}/bugzilla.conf
CONF_FILES_PERMS=	${EGDIR}/localconfig ${BZDIR}/localconfig \
			${APACHE_USER} ${SHAREGRP} 0400
PAX_DIRS=	Bugzilla skins template

REPLACE_PERL+=	*.pl *.cgi

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

post-extract:
	${FIND} ${WRKSRC} -type d -name CVS | ${XARGS} ${RM} -rf
	${FIND} ${WRKSRC} -type f -name ".cvsignore" | ${XARGS} ${RM} -f
	${CP} ${FILESDIR}/bugzilla.conf ${WRKSRC}
	${CP} ${FILESDIR}/localconfig ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${BZDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${BZDIR}/Bugzilla

	${INSTALL_DATA_DIR} ${DESTDIR}${BZDIR}/js
	${INSTALL_DATA_DIR} ${DESTDIR}${BZDIR}/template
	${INSTALL_DATA_DIR} ${DESTDIR}${BZDIR}/skins
	${INSTALL_DATA_DIR} ${DESTDIR}${BZDIR}/docs
	${INSTALL_DATA_DIR} ${DESTDIR}${BZDIR}/docs/html
	${INSTALL_DATA_DIR} ${DESTDIR}${BZDIR}/images

	${INSTALL_DATA} ${WRKSRC}/docs/txt/Bugzilla-Guide.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/rel_notes.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/QUICKSTART ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING-pre-2.8 ${DESTDIR}${DOCDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${DESTDIR}${BZDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${DESTDIR}${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/*.js ${DESTDIR}${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/bugzilla.dtd ${DESTDIR}${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/duplicates.xul ${DESTDIR}${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/Bugzilla.pm ${DESTDIR}${BZDIR}

	${INSTALL_DATA} ${WRKSRC}/bugzilla.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/localconfig ${DESTDIR}${EGDIR}

	${INSTALL_DATA} ${WRKSRC}/images/*.png ${DESTDIR}${BZDIR}/images
	${INSTALL_DATA} ${WRKSRC}/js/*.js ${DESTDIR}${BZDIR}/js
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.html ${DESTDIR}${BZDIR}/docs/html

.for i in ${PAX_DIRS}
	cd ${WRKSRC}/${i} && pax -rw . ${DESTDIR}${BZDIR}/${i}
	${FIND} ${DESTDIR}${BZDIR}/${i} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${BZDIR}/${i} -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${BZDIR}/${i}
.endfor

	${CHMOD} ${SHAREMODE} ${DESTDIR}${BZDIR}/globals.pl

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
