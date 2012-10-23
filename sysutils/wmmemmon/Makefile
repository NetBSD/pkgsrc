# $NetBSD: Makefile,v 1.12 2012/10/23 10:24:11 wiz Exp $
#

DISTNAME=	wmmemmon-1.0.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://seiichisato.jp/dockapps/src/

MAINTAINER=	coto@core.de
HOMEPAGE=	http://seiichisato.jp/dockapps/\#wmmemmon
COMMENT=	Dockapp to monitor memory and swap usages

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

post-extract:
	${CP} ${FILESDIR}/mem_dragonfly.c ${WRKSRC}/src

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
