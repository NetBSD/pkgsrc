# $NetBSD: Makefile,v 1.49 2023/06/06 09:54:12 bouyer Exp $

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
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
