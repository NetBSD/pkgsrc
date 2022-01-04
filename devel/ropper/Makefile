# $NetBSD: Makefile,v 1.7 2022/01/04 20:53:50 wiz Exp $

DISTNAME=	Ropper-1.11.6
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sashs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sashs/Ropper/
COMMENT=	Display information about executables and search for gadgets
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-capstone-[0-9]*:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-filebytes-[0-9]*:../../devel/py-filebytes
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-keystone-[0-9]*:../../emulators/py-keystone

USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/${DISTNAME}
EGG_NAME=	${DISTNAME:tl}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
