# $NetBSD: Makefile,v 1.51 2023/11/12 13:20:47 wiz Exp $

PKGREVISION= 1
.include "../../cad/ng-spice/Makefile.common"

PKGNAME=	ng-spice-${VERSION}
COMMENT=	Next generation circuit simulation program
USE_TOOLS+=	makeinfo

CONFIGURE_ARGS+=	--with-readline=yes
LIBS+=			${BUILDLINK_LDADD.getopt}

INFO_FILES=	yes
TEXINFO_REQD=	4.6

.include "../../devel/libgetopt/buildlink3.mk"
# uses rl_* interface
.include "../../devel/readline/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
