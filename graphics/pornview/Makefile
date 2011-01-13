# $NetBSD: Makefile,v 1.14 2011/01/13 13:38:15 wiz Exp $
#

PKGNAME=	pornview-0.2.0pre1
DISTNAME=	pornview_0.2pre1.orig
PKGREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/pornview/}

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://pornview.sourceforge.net/
COMMENT=	GTK+ image viewer

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/pornview-0.2.0pre1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

USE_TOOLS+=		intltool msgfmt perl:run
REPLACE_PERL+=		src/scripts/helloworld

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
