# $NetBSD: Makefile,v 1.8 2002/09/10 16:06:43 wiz Exp $

DISTNAME=	ogle_gui-0.8.5
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	GUI for the Ogle DVD player

DEPENDS+=	ogle>=0.8.5:../../graphics/ogle
# Normally, we would use the "../../devel/libglade/buildlink.mk" file,
# but this doesn't work here, because ogle_gui wants libxml2 and the
# buildlink file for libglade would also link it with libxml1.
# This would result in an core dump. Thats why ogle_gui dlopens
# libglade.
DEPENDS+=	libglade>=0.17nb1:../../devel/libglade

CONFIGURE_ARGS+=--bindir=${PREFIX}/lib/ogle

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_CONFIG_WRAPPER=	yes
#USE_LIBTOOL=		yes
#LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LDFLAGS+=	-Wl,-R${LOCALBASE}/lib/ogle -L${LOCALBASE}/lib/ogle

.include "../../devel/binutils/buildlink.mk"
.include "../../lang/gcc/Makefile.gcc"

.include "../../textproc/libxml2/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
