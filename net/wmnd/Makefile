# $NetBSD: Makefile,v 1.9 2013/11/16 07:17:24 shattered Exp $

DISTNAME=	wmnd-0.4.17
CATEGORIES=	net x11
MASTER_SITES=	http://www.thregr.org/~wavexx/software/wmnd/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.thregr.org/~wavexx/software/wmnd/
COMMENT=	Dockable network monitor

DIST_SUBDIR=	${PKGNAME_NOREV}

GNU_CONFIGURE=	YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
