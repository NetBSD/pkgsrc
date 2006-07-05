# $NetBSD: Makefile,v 1.12 2006/07/05 05:37:41 jlam Exp $
#

DISTNAME=		refocus-it-2.0.0
PKGNAME=		gimp-refocus-it-2.0.0
PKGREVISION=		6
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=refocus-it/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://refocus-it.sourceforge.net/
COMMENT=		Refocus images

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
#just build the plugin
CONFIGURE_ARGS+=	--without-cmdline
USE_TOOLS+=		intltool msgfmt pkg-config

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
