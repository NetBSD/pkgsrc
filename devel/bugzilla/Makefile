# $NetBSD: Makefile,v 1.27 2007/12/22 07:22:06 obache Exp $
#

DISTNAME=	bugzilla-2.22.3
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=webtools/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.bugzilla.org/
COMMENT=	Web based bug tracking system

DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=	p5-CGI>=2.93:../../www/p5-CGI
DEPENDS+=	p5-DBI>=1.38:../../databases/p5-DBI
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp
DEPENDS+=	p5-Template-Toolkit>=2.10:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Tabs+Wrap>=2001.0131:../../textproc/p5-Text-Tabs+Wrap
DEPENDS+=	p5-Storable-[0-9]*:../../devel/p5-Storable
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
DEPENDS+=	p5-MailTools>=1.74:../../mail/p5-MailTools
DEPENDS+=	p5-MIME-Base64>=3.01:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MIME-tools>=5.406:../../mail/p5-MIME-tools

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

USE_TOOLS+=	perl:run
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
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${BZDIR}
	${INSTALL_DATA_DIR} ${BZDIR}/Bugzilla

	${INSTALL_DATA_DIR} ${BZDIR}/js
	${INSTALL_DATA_DIR} ${BZDIR}/template
	${INSTALL_DATA_DIR} ${BZDIR}/skins
	${INSTALL_DATA_DIR} ${BZDIR}/docs
	${INSTALL_DATA_DIR} ${BZDIR}/docs/html
	${INSTALL_DATA_DIR} ${BZDIR}/images

	${INSTALL_DATA} ${WRKSRC}/docs/txt/Bugzilla-Guide.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/rel_notes.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/QUICKSTART ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING-pre-2.8 ${DOCDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${BZDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/*.js ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/bugzilla.dtd ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/duplicates.xul ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/Bugzilla.pm ${BZDIR}

	${INSTALL_DATA} ${WRKSRC}/bugzilla.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/localconfig ${EGDIR}

	${INSTALL_DATA} ${WRKSRC}/images/*.png ${BZDIR}/images
	${INSTALL_DATA} ${WRKSRC}/js/*.js ${BZDIR}/js
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.html ${BZDIR}/docs/html

.for i in ${PAX_DIRS}
	cd ${WRKSRC}/${i} && ${PAX} -rw . ${BZDIR}/${i}
	${FIND} ${BZDIR}/${i} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${BZDIR}/${i} -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${BZDIR}/${i}
.endfor

	${CHMOD} ${SHAREMODE} ${BZDIR}/globals.pl

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
