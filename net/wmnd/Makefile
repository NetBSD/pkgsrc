# $NetBSD: Makefile,v 1.11 2020/11/24 11:41:23 nia Exp $

DISTNAME=	wmnd-0.4.18
CATEGORIES=	net x11
MASTER_SITES=	https://www.thregr.org/~wavexx/software/wmnd/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.thregr.org/~wavexx/software/wmnd/
COMMENT=	Dockable network monitor
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	${PKGNAME_NOREV}

GNU_CONFIGURE=	YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
