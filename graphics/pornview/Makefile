# $NetBSD: Makefile,v 1.2 2006/02/13 15:23:03 rillig Exp $
#

PKGNAME=	pornview-0.2.0pre1
DISTNAME=	pornview_0.2pre1.orig
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/pornview/}

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://pornview.sourceforge.net/
COMMENT=	GTK+ image viewer

WRKSRC=			${WRKDIR}/pornview-0.2.0pre1

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

USE_TOOLS+=		perl:run
REPLACE_PERL+=		src/scripts/helloworld

.include "options.mk"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
