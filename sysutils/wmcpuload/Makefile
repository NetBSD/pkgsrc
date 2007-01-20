# $NetBSD: Makefile,v 1.10 2007/01/20 12:56:27 joerg Exp $
#

DISTNAME=	wmcpuload-1.0.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	coto@core.de
HOMEPAGE=	http://www.sh.rim.or.jp/~ssato/dockapp/\#wmcpuload
COMMENT=	Dockable CPU monitor

GNU_CONFIGURE= 	YES

post-extract:
	${CP} ${FILESDIR}/cpu_dragonfly.c ${WRKSRC}/src

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
