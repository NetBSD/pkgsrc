# $NetBSD: Makefile,v 1.55 2004/11/20 22:10:22 jmmv Exp $

DISTNAME=		libglade-0.17
PKGREVISION=		7
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libglade/0.17/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Runtime interpreter for GLADE GUI files

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

MAKE_ENV+=	DISPLAY=${DISPLAY}

.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../mk/bsd.pkg.mk"
