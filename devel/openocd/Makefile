# $NetBSD: Makefile,v 1.3 2017/09/16 19:26:46 wiz Exp $

DISTNAME=	openocd-0.9.0
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
MAKE_JOBS_SAFE=	no
INFO_FILES=	yes

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

.include "options.mk"

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
