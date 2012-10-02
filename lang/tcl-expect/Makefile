# $NetBSD: Makefile,v 1.27 2012/10/02 20:11:55 asau Exp $

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extensions to Tcl to support scripting of interactive programs
LICENSE=	public-domain

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--without-x

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
