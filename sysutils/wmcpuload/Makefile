# $NetBSD: Makefile,v 1.12 2008/01/04 08:00:50 obache Exp $
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
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
