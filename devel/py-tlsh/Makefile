# $NetBSD: Makefile,v 1.1 2015/12/02 17:22:57 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/py_ext

USE_LANGUAGES=	c c++
EGG_NAME=	tlsh-0.2.0

.include "../../devel/tlsh/Makefile.common"
.include "../../devel/tlsh/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
