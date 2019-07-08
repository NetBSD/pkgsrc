# $NetBSD: Makefile,v 1.6 2019/07/08 16:27:13 martin Exp $

DISTNAME=	openocd-0.10.0
PKGREVISION=	1
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
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "options.mk"

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
