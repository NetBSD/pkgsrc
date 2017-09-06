# $NetBSD: Makefile,v 1.14 2017/09/06 10:40:33 wiz Exp $
#

DISTNAME=	wmmemmon-1.0.1
PKGREVISION=	1
CATEGORIES=	sysutils
#MASTER_SITES=	http://seiichisato.jp/dockapps/src/

MAINTAINER=	coto@core.de
#HOMEPAGE=	http://seiichisato.jp/dockapps/\#wmmemmon
COMMENT=	Dockapp to monitor memory and swap usages

GNU_CONFIGURE=	YES

post-extract:
	${CP} ${FILESDIR}/mem_dragonfly.c ${WRKSRC}/src

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
