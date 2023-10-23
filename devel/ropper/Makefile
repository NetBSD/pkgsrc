# $NetBSD: Makefile,v 1.10 2023/10/23 06:37:43 wiz Exp $

DISTNAME=	Ropper-1.11.6
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sashs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sashs/Ropper/
COMMENT=	Display information about executables and search for gadgets
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-capstone-[0-9]*:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-filebytes-[0-9]*:../../devel/py-filebytes
DEPENDS+=	${PYPKGPREFIX}-keystone-[0-9]*:../../emulators/py-keystone

USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/${DISTNAME}
EGG_NAME=	${DISTNAME:tl}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
