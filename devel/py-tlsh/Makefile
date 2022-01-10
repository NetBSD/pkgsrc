# $NetBSD: Makefile,v 1.2 2022/01/10 18:56:35 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/py_ext

USE_LANGUAGES=	c c++
EGG_NAME=	tlsh-0.2.0

.include "../../devel/tlsh/Makefile.common"
.include "../../devel/tlsh/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
