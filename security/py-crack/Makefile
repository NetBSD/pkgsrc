# $NetBSD: Makefile,v 1.16 2022/01/22 14:28:27 wiz Exp $

DISTNAME=	pycrack-0.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/py//}
PKGREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	http://www.digitalevacuation.org/pycrack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.digitalevacuation.org/
COMMENT=	Python interface to cracklib
LICENSE=	gnu-gpl-v2

DEPENDS+=			crack>=5.0:../../security/crack

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} != "py27"
EGG_NAME=	pycrack-0.1
.endif

.include "../../lang/python/egg.mk"
.include "../../security/libcrack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
