# $NetBSD: Makefile,v 1.14 2023/07/17 22:00:22 nia Exp $

DISTNAME=		goom-2k4-0-src
PKGNAME=		goom-2004.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=goom/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.fovea.cc/?page=details_produits&id=goom
COMMENT=		Visual effects generator for mp3 players
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/goom2k4-0
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgoom2.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

# "This package needs gcc-3.0 because it uses some inline assembler syntax
# that gcc-2.95.3 does not understand."
GCC_REQD+=		3.3

# convolve_fx.c: In function 'create_output_with_brightness':
# convolve_fx.c:222:20: error: array subscript has type 'char' [-Werror=char-subscripts]
#        iff2 = ifftab[data->conv_motif[(ytex >>16) & CONV_MOTIF_WMASK][(xtex >> 16) & CONV_MOTIF_WMASK]];
#                     ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
