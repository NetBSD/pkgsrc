# $NetBSD: Makefile,v 1.15 2005/04/05 14:56:06 cube Exp $

DISTNAME=	lv451
PKGNAME=	lv-4.51
CATEGORIES=	misc
MASTER_SITES=	http://www.ff.iij4u.or.jp/~nrt/freeware/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.ff.iij4u.or.jp/~nrt/lv/
COMMENT=	Powerful Multilingual File Viewer

WRKSRC=		${WRKDIR}/${DISTNAME}/build
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../src/configure

MAKE_ENV+=	LN=${LN}
INSTALLATION_DIRS=	lib/lv

.include "../../mk/bsd.pkg.mk"
