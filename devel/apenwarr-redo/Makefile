# $NetBSD: Makefile,v 1.5 2020/07/06 16:26:58 leot Exp $

DISTNAME=	redo-0.42c
PKGNAME=	apenwarr-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=apenwarr/}
GITHUB_PROJECT=	redo
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/apenwarr/redo/
COMMENT=	Python implementation of DJB's redo build tool
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
BUILD_DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown

DEPENDS+=	dash-[0-9]*:../../shells/dash
DEPENDS+=	${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

WRKSRC=		${WRKDIR}/redo-${DISTNAME}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	redo/whichpython.do
SUBST_VARS.paths=	PYTHONBIN

INSTALL_ENV+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/bin; \
	for i in *; do mv -f $${i} apenwarr-$${i}; done
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	for i in *; do mv -f $${i} apenwarr-$${i}; done

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
