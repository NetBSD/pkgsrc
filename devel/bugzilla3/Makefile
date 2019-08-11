# $NetBSD: Makefile,v 1.30 2019/08/11 13:18:39 wiz Exp $

DISTNAME=	bugzilla-3.6.8
PKGREVISION=	2
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=webtools/archived/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bugzilla.org/
COMMENT=	Web based bug tracking system
LICENSE=	mpl-1.0

DEPENDS+=	p5-CGI>=3.21:../../www/p5-CGI
DEPENDS+=	p5-DBI>=1.41:../../databases/p5-DBI
DEPENDS+=	p5-Template-Toolkit>=2.15:../../www/p5-Template-Toolkit
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
DEPENDS+=	p5-Email-Send>=2.00:../../mail/p5-Email-Send
DEPENDS+=	p5-Email-MIME>=1.903:../../mail/p5-Email-MIME

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
PAX_DIRS=		Bugzilla skins template

REPLACE_PERL+=	*.pl *.cgi

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_MESSAGE.conf=	Fixing configuration files.
SUBST_FILES.conf=	bugzilla.conf localconfig Bugzilla/BugMail.pm
SUBST_VARS.conf=	BZ_WEB_GROUP
SUBST_VARS.conf+=	PREFIX
SUBST_VARS.conf+=	BZDIR
SUBST_VARS.conf+=	CVS
SUBST_VARS.conf+=	DBDRIVER
SUBST_SED.conf+=	-e "s|/usr/lib/sendmail|${SENDMAIL}|g"

INSTALLATION_DIRS+=	${DOCDIR} ${DOCDIR}/en ${EGDIR} ${BZDIR} ${BZDIR}/Bugzilla
INSTALLATION_DIRS+=	${BZDIR}/js ${BZDIR}/lib ${BZDIR}/template ${BZDIR}/skins
INSTALLATION_DIRS+=	${BZDIR}/docs ${BZDIR}/docs/en ${BZDIR}/docs/en/html
INSTALLATION_DIRS+=	${BZDIR}/images ${BZDIR}/docs/en/html/api
INSTALLATION_DIRS+=	${BZDIR}/docs/en/html/api/Bugzilla

post-extract:
	${FIND} ${WRKSRC} -type d -name CVS | ${XARGS} ${RM} -rf
	${FIND} ${WRKSRC} -type f -name ".cvsignore" | ${XARGS} ${RM} -f
	${CP} ${FILESDIR}/bugzilla.conf ${WRKSRC}
	${CP} ${FILESDIR}/localconfig ${WRKSRC}

do-install:

	${INSTALL_DATA} ${WRKSRC}/docs/en/txt/Bugzilla-Guide.txt ${DESTDIR}${DOCDIR}/en
	${INSTALL_DATA} ${WRKSRC}/docs/en/rel_notes.txt ${DESTDIR}${DOCDIR}/en
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${DESTDIR}${BZDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${DESTDIR}${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/bugzilla.dtd ${DESTDIR}${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/Bugzilla.pm ${DESTDIR}${BZDIR}

	${INSTALL_DATA} ${WRKSRC}/bugzilla.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/localconfig ${DESTDIR}${EGDIR}

	${INSTALL_DATA} ${WRKSRC}/images/*.png ${DESTDIR}${BZDIR}/images
	${INSTALL_DATA} ${WRKSRC}/js/*.js ${DESTDIR}${BZDIR}/js
	${INSTALL_DATA} ${WRKSRC}/docs/en/html/*.html ${DESTDIR}${BZDIR}/docs/en/html
	${INSTALL_DATA} ${WRKSRC}/docs/en/html/api/*.html ${DESTDIR}${BZDIR}/docs/en/html/api
	${INSTALL_DATA} ${WRKSRC}/docs/en/html/api/Bugzilla/*.html ${DESTDIR}${BZDIR}/docs/en/html/api/Bugzilla

.for i in ${PAX_DIRS}
	cd ${WRKSRC}/${i} && pax -rw . ${DESTDIR}${BZDIR}/${i}
	${FIND} ${DESTDIR}${BZDIR}/${i} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${BZDIR}/${i} -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${BZDIR}/${i}
.endfor

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
