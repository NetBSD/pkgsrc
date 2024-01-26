# $NetBSD: Makefile,v 1.1 2024/01/26 13:13:35 wiz Exp $

DISTNAME=	tclx-8.6.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=flightaware/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flightaware/tclx/
COMMENT=	Extension to Tcl
LICENSE=	2-clause-bsd

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "aarch64"
CONFIGURE_ARGS+=	--enable-64bit
.elif ${MACHINE_ARCH} == "sparc64"
CONFIGURE_ARGS+=	--enable-64bit-vis
.endif

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
