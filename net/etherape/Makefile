# $NetBSD: Makefile,v 1.3 2002/10/06 03:02:07 wiz Exp $

DISTNAME=	etherape-0.8.2
PKGREVISION=	1
CATEGORIES=	gnome net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=etherape/}

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://etherape.sourceforge.net/
COMMENT=	graphical network monitor

USE_GMAKE=		#defined
USE_X11BASE=		#defined
USE_BUILDLINK2=		#defined
HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--prefix ${PREFIX}
PLIST_SUBST+=		MKDIR='${MKDIR}'

.include "../../devel/libglade/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
