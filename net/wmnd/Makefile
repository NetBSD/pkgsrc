# $NetBSD: Makefile,v 1.10 2020/01/26 17:31:58 rillig Exp $

DISTNAME=	wmnd-0.4.17
CATEGORIES=	net x11
MASTER_SITES=	http://www.thregr.org/~wavexx/software/wmnd/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.thregr.org/~wavexx/software/wmnd/
COMMENT=	Dockable network monitor

DIST_SUBDIR=	${PKGNAME_NOREV}

GNU_CONFIGURE=	YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
