# $NetBSD: Makefile,v 1.2 2017/08/07 17:56:13 jlam Exp $

DISTNAME=	dehydrated-0.4.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=lukas2511/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/lukas2511/dehydrated
COMMENT=	Letsencrypt/acme client implemented as a shell-script
LICENSE=	mit

GITHUB_PROJECT=	dehydrated
GITHUB_TAG=	v${PKGVERSION_NOREV}

NO_BUILD=	yes

USE_TOOLS+=	bash:run sed:run awk:run curl:run pax openssl
REPLACE_BASH=	dehydrated test.sh docs/examples/hook.sh

PKG_SYSCONFSUBDIR=	dehydrated
EGDIR=			${PREFIX}/share/examples/dehydrated
CONF_FILES=		${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${EGDIR}/domains.txt ${PKG_SYSCONFDIR}/domains.txt
DOCDIR=			share/doc/dehydrated
INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR} bin
AUTO_MKDIRS=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-extract
SUBST_FILES.paths=	${WRKSRC}/dehydrated
SUBST_SED.paths=	-e 's|/usr/local/etc|${PKG_SYSCONFBASE}|g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dehydrated ${DESTDIR}${PREFIX}/bin/dehydrated
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}
	cd ${WRKSRC}/docs && pax -rw *.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/examples/config ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/examples/domains.txt ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/examples/hook.sh ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
