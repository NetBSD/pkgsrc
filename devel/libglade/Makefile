# $NetBSD: Makefile,v 1.61 2006/10/04 21:35:59 wiz Exp $

DISTNAME=		libglade-0.17
PKGREVISION=		9
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libglade/0.17/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.jamesh.id.au/software/libglade/
COMMENT=		Runtime interpreter for GLADE GUI files

USE_TOOLS+=		msgfmt
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

MAKE_ENV+=	DISPLAY=${DISPLAY:Q}

.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../mk/bsd.pkg.mk"
