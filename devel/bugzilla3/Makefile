# $NetBSD: Makefile,v 1.8.4.1 2008/11/15 16:55:29 tron Exp $
#

DISTNAME=	bugzilla-3.0.6
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=webtools/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.bugzilla.org/
COMMENT=	Web based bug tracking system

DEPENDS+=	p5-CGI>=2.93:../../www/p5-CGI
DEPENDS+=	p5-DBI>=1.41:../../databases/p5-DBI
DEPENDS+=	p5-Template-Toolkit>=2.12:../../www/p5-Template-Toolkit
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
DEPENDS+=	p5-Email-Send>=2.185:../../mail/p5-Email-Send
DEPENDS+=	p5-Email-MIME-Modifier-[0-9]*:../../mail/p5-Email-MIME-Modifier

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

USE_TOOLS+=	pax perl:run
NO_BUILD=	YES

BZ_WEB_GROUP?=	${APACHE_GROUP}
SENDMAIL?=	/usr/sbin/sendmail
CVS?=		/usr/bin/cvs

BUILD_DEFS+=	SENDMAIL CVS APACHE_USER APACHE_GROUP
PERL5_REQD+=	5.8.0

PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	BZ_WEB_GROUP APACHE_GROUP

MESSAGE_SUBST+=	BZDIR=${BZDIR:Q} PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

BZDIR=			${PREFIX}/share/bugzilla
EGDIR=			${PREFIX}/share/examples/bugzilla
DOCDIR=			${PREFIX}/share/doc/bugzilla
CONF_FILES=		${EGDIR}/bugzilla.conf ${PKG_SYSCONFDIR}/bugzilla.conf
CONF_FILES_PERMS=	${EGDIR}/localconfig ${BZDIR}/localconfig \
			${APACHE_USER} ${SHAREGRP} 0400
PAX_DIRS=		Bugzilla skins template

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

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
