# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:31 joerg Exp $
#

DISTNAME=		refocus-it-2.0.0
PKGNAME=		gimp-refocus-it-2.0.0
PKGREVISION=		4
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
