# $NetBSD: Makefile,v 1.2 2025/09/30 16:07:39 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-2.4.0
PKGNAME=	${DISTNAME:S/mod/${APACHE_PKG_PREFIX}/:S/_/-/g}
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_GITHUB:=jvdmr/}
GITHUB_PROJECT=	mod_evasive
GITHUB_TAG=	refs/tags/${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	https://github.com/jvdmr/mod_evasive
COMMENT=	Apache Evasive Maneuvers Module
LICENSE=	gnu-gpl-v2

AP_VERSION=	24

APACHE_MODULE=		YES
APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=	${DISTNAME:C|-.*||}.c
APACHE_MODULE_LA=	${DISTNAME:C|-.*||}.la

USE_TOOLS+=		mail

SUBST_CLASSES+=		mailer
SUBST_STAGE.mailer=	pre-configure
SUBST_FILES.mailer=	${GITHUB_PROJECT}${AP_VERSION}.c
SUBST_SED.mailer=	-e s,/bin/mail,${MAIL_CMD},
SUBST_MESSAGE.mailer=	Fixing mail command path.

do-build:
	mv ${WRKSRC}/${DISTNAME:C|-.*||}${AP_VERSION}.c ${WRKSRC}/${APACHE_MODULE_SRC}
	cd ${WRKSRC} && ${APXS} -c -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_SRC}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/httpd
	cd ${WRKSRC} && ${APXS} -S LIBEXECDIR=${DESTDIR}${PREFIX}/lib/httpd -i -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_LA}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/httpd/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/httpd/manual/mod
	${INSTALL_DATA} ${WRKSRC}/mod_evasive.conf ${DESTDIR}${PREFIX}/share/examples/httpd/mod_evasive.conf
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/httpd/manual/mod/mod_evasive.md

.include "../../mk/apache.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
