# $NetBSD: Makefile,v 1.34 2018/09/07 08:51:39 jperkin Exp $

.include "Makefile.common"

PKGNAME=	tcl-expect-${EXPECT_VERSION}
PKGREVISION=	4
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extensions to Tcl to support scripting of interactive programs
LICENSE=	public-domain

USE_GCC_RUNTIME=	yes

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-tclconfig=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--without-x

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}

.include "../../mk/bsd.prefs.mk"

# XXX: libexpect should have .dylib suffix
.if ${OPSYS} == "Darwin"
post-build:
	install_name_tool -id ${PREFIX}/lib/libexpect${EXPECT_SONUM}.so \
		${WRKSRC}/libexpect${EXPECT_SONUM}.so
	install_name_tool -change libexpect${EXPECT_SONUM}.so \
		${PREFIX}/lib/libexpect${EXPECT_SONUM}.so ${WRKSRC}/expect
.endif

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
