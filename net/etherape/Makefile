# $NetBSD: Makefile,v 1.2 2002/03/13 17:37:28 fredb Exp $

DISTNAME=	etherape-0.8.2
PKGREVISION=	1
CATEGORIES=	gnome net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=etherape/}

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://etherape.sourceforge.net/
COMMENT=	graphical network monitor

USE_GMAKE=		#defined
USE_X11BASE=		#defined
HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--prefix ${PREFIX}
PLIST_SUBST+=		MKDIR='${MKDIR}'

.include "../../devel/libglade/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
