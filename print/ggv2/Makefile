# $NetBSD: Makefile,v 1.2 2002/12/24 06:10:21 wiz Exp $
#

DISTNAME=		ggv-1.99.95
PKGREVISION=		1
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ggv/1.99/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 frontend for GhostScript

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_X11=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}

.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
