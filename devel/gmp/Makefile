# $NetBSD: Makefile,v 1.34 2005/03/15 15:51:30 wiz Exp $

DISTNAME=	gmp-4.1.4
PKGREVISION=	1
CATEGORIES=	devel math
MASTER_SITES=	${MASTER_SITE_GNU:=gmp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gmp/gmp.html
COMMENT=	Library for arbitrary precision arithmetic

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_GNU_TOOLS+=		m4
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-cxx --without-readline

INFO_FILES=		gmp.info

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"
.if !empty(LOWER_OPSYS:Mirix5) && !empty(ABI)
ABI=			o32
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
# The configure script thinks gcc 2.95 for ARM is too buggy to use.
GCC_REQD+=		3.0
.endif

.include "../../mk/bsd.pkg.mk"
