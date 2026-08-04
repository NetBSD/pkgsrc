# $NetBSD: Makefile,v 1.88 2026/08/04 20:29:08 wiz Exp $

DISTNAME=		xmgr-4.1.2
PKGREVISION=		53
CATEGORIES=		math
#MASTER_SITES=		ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://plasma-gate.weizmann.ac.il/Xmgr/
COMMENT=		Powerful XY plotting tool for workstations or X-terminals using X
LICENSE=		modified-bsd

USE_LANGUAGES=		c fortran77
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-acegr-home=${PREFIX:Q}

BUILD_TARGET=		# empty
INSTALL_TARGET=		install

REPLACE_PERL+=		auxiliary/fdf2fit
USE_TOOLS+=		perl:run bison

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/netcdf/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
