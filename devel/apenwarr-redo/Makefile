# $NetBSD: Makefile,v 1.1 2019/07/20 21:17:11 schmonz Exp $

DISTNAME=	redo-0.41
PKGNAME=	apenwarr-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	-https://codeload.github.com/apenwarr/redo/tar.gz/${DISTNAME}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/apenwarr/redo/
COMMENT=	Python implementation of DJB's redo build tool
LICENSE=	apache-2.0

CONFLICTS+=	jdebp-redo-[0-9]*

PYTHON_VERSIONS_ACCEPTED=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup-[0-9]*:../../www/py-beautifulsoup
BUILD_DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown

DEPENDS+=	dash-[0-9]*:../../shells/dash
DEPENDS+=	${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

WRKSRC=		${WRKDIR}/redo-${DISTNAME}

INSTALL_ENV+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
