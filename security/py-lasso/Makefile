# $NetBSD: Makefile,v 1.1.1.1 2009/03/02 16:46:26 manu Exp $
#

PKGNAME=	${PYPKGPREFIX}-lasso
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

