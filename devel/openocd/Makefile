# $NetBSD: Makefile,v 1.8 2021/05/06 21:15:38 tnn Exp $

DISTNAME=	openocd-0.11.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openocd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openocd.org/
COMMENT=	Open On-Chip Debugger
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
INFO_FILES=	yes

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--disable-internal-jimtcl
BUILDLINK_TRANSFORM+=	rm:-Werror
OVERRIDE_DIRDEPTH?=	5

.include "options.mk"

.include "../../lang/jimtcl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
