# $NetBSD: Makefile,v 1.2 2005/04/11 21:46:03 tv Exp $
#

DISTNAME=		refocus-it-2.0.0
PKGNAME=		gimp-refocus-it-2.0.0
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=refocus-it/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://refocus-it.sourceforge.net/
COMMENT=		Refocus images

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
#just build the plugin
CONFIGURE_ARGS+=	--without-cmdline

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
