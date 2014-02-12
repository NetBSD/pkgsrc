# $NetBSD: Makefile,v 1.24 2014/02/12 00:57:25 prlw1 Exp $

.include "Makefile.common"

PKGNAME=		${PYPKGPREFIX}-gobject3-${VER}
PKGREVISION=		1

COMMENT=		Python bindings for glib2 gobject

CONFIGURE_ARGS+=	--without-common

.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
