# $NetBSD: Makefile,v 1.66 2020/03/20 11:57:48 nia Exp $

DISTNAME=	gphoto2-2.5.8
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/
COMMENT=	Digital camera access command line client
LICENSE=	gnu-gpl-v2

CONFLICTS=		gphoto-[0-9]*

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cdk-prefix=${BUILDLINK_PREFIX.cdk}
CONFIGURE_ARGS+=	--with-jpeg-prefix=${JPEGBASE}

CFLAGS.Darwin+=	-D_DARWIN_C_SOURCE

.include "../../devel/cdk/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
# uses rl_completion_matches() (NetBSD 3.* don't have) and rl_copy_text()
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
