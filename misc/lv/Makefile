# $NetBSD: Makefile,v 1.12 2004/01/20 12:21:02 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1999/01/08 03:32:06 itojun Exp $

DISTNAME=	lv450
PKGNAME=	lv-4.50
CATEGORIES=	misc
MASTER_SITES=	http://www.ff.iij4u.or.jp/~nrt/freeware/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.ff.iij4u.or.jp/~nrt/lv/
COMMENT=	Powerful Multilingual File Viewer

WRKSRC=		${WRKDIR}/${DISTNAME}/build
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../src/configure

# Causes unaligned access fault...
# Note that the 32bit (sparc) binary works fine.
NOT_FOR_PLATFORM= NetBSD-*-sparc64

.include "../../mk/bsd.pkg.mk"
