# $NetBSD: Makefile,v 1.17 2020/11/24 10:57:01 nia Exp $

DISTNAME=	wmcpuload-1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	coto@core.de
HOMEPAGE=	https://www.dockapps.net/wmcpuload
COMMENT=	Dockable CPU monitor

GNU_CONFIGURE=	YES

post-extract:
	${CP} ${FILESDIR}/cpu_dragonfly.c ${WRKSRC}/src

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
