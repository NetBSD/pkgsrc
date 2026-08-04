# $NetBSD: Makefile,v 1.2 2026/08/04 20:29:03 wiz Exp $

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
