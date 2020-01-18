# $NetBSD: Makefile,v 1.62 2020/01/18 23:32:11 rillig Exp $

DISTNAME=		refocus-it-2.0.0
PKGNAME=		gimp-refocus-it-2.0.0
PKGREVISION=		51
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=refocus-it/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://refocus-it.sourceforge.net/
COMMENT=		Refocus images

DEPENDS+=		refocus-it-[0-9]*:../../graphics/refocus-it

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
#just build the plugin
CONFIGURE_ARGS+=	--without-cmdline
USE_FEATURES=		asprintf
USE_TOOLS+=		intltool pkg-config
MAKE_FLAGS=		SUBDIRS='src gimp-plugin'

PTHREAD_AUTO_VARS=	yes

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
