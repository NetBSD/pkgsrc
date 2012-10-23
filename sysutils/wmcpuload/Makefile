# $NetBSD: Makefile,v 1.15 2012/10/23 19:51:34 asau Exp $
#

DISTNAME=	wmcpuload-1.0.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://seiichisato.jp/dockapps/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	coto@core.de
HOMEPAGE=	http://seiichisato.jp/dockapps/
COMMENT=	Dockable CPU monitor

GNU_CONFIGURE=	YES

post-extract:
	${CP} ${FILESDIR}/cpu_dragonfly.c ${WRKSRC}/src

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
