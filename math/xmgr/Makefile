# $NetBSD: Makefile,v 1.72 2022/06/28 11:34:45 wiz Exp $

DISTNAME=		xmgr-4.1.2
PKGREVISION=		38
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

.include "../../devel/netcdf/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
