# $NetBSD: Makefile,v 1.2 2001/12/12 01:32:33 enami Exp $

DISTNAME=	ogle_gui-0.8.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	GUI for the Ogle DVD player

DEPENDS+=	ogle>=0.8.2:../../graphics/ogle
# Normaly we would use the "../../devel/libglade/buildlink.mk" file,
# but this doesn't work here. Because ogle_gui wants libxml2 and the
# buildlink file for libglade would also link it with libxml1.
# This would result in an core dump. Thats why ogle_gui dlopens
# libglade.
DEPENDS+=	libglade>=0.17:../../devel/libglade

CONFIGURE_ARGS+=--bindir=${PREFIX}/lib/ogle

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
#USE_LIBTOOL=	yes
BUILDLINK_DEPENDS.libxml2=	libxml2>=2.4.5
#LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LDFLAGS+=	-Wl,-R${LOCALBASE}/lib/ogle -L${LOCALBASE}/lib/ogle

.include "../../textproc/libxml2/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
