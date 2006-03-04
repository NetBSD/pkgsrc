# $NetBSD: Makefile,v 1.7 2006/03/04 21:29:48 jlam Exp $
#

DISTNAME=		refocus-it-2.0.0
PKGNAME=		gimp-refocus-it-2.0.0
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=refocus-it/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://refocus-it.sourceforge.net/
COMMENT=		Refocus images

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
#just build the plugin
CONFIGURE_ARGS+=	--without-cmdline

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
