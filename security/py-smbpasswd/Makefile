# $NetBSD: Makefile,v 1.12 2022/01/19 18:11:02 wiz Exp $

DISTNAME=	py-smbpasswd-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://barryp.org/static/software/download/py-smbpasswd/1.0.1/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://barryp.org/software/py-smbpasswd/
COMMENT=	Python SMB Password Hash Generator

EGG_NAME=	smbpasswd-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
