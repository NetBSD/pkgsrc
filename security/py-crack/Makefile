# $NetBSD: Makefile,v 1.14 2020/07/13 20:05:12 wiz Exp $

DISTNAME=	pycrack-0.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/py//}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	http://www.digitalevacuation.org/pycrack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.digitalevacuation.org/
COMMENT=	Python interface to cracklib
LICENSE=	gnu-gpl-v2

DEPENDS+=			crack>=5.0:../../security/crack

.include "../../lang/python/distutils.mk"
.include "../../security/libcrack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
