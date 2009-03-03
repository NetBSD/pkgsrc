# $NetBSD: Makefile,v 1.2 2009/03/03 10:53:15 manu Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
COMMENT=	Libery Alliance Single Sign On binding for Python

PKG_DESTDIR_SUPPORT=	destdir

CONFIGURE_ARGS+=	--disable-php4
CONFIGURE_ARGS+=	--disable-perl

do-install:
	cd ${WRKSRC}/bindings/python && ${MAKE} install

PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"

.include "../../security/lasso/buildlink3.mk"

.include "../../security/lasso/Makefile.common"

