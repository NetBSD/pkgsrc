# $NetBSD: Makefile,v 1.34 2001/10/24 22:10:53 jlam Exp $
#

DISTNAME=		libglade-0.17
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/libglade/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Runtime interpreter for GLADE gui files

BUILD_USES_MSGFMT=	yes

USE_LIBTOOL=		YES
USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../audio/esound/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
