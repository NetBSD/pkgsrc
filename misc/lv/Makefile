# $NetBSD: Makefile,v 1.7 2002/02/22 02:20:46 minoura Exp $
# FreeBSD Id: Makefile,v 1.3 1999/01/08 03:32:06 itojun Exp $

DISTNAME=	lv4494
PKGNAME=	lv-4.49.4
CATEGORIES=	misc
MASTER_SITES=	http://www.ff.iij4u.or.jp/~nrt/freeware/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.ff.iij4u.or.jp/~nrt/lv/
COMMENT=	Powerful Multilingual File Viewer

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../src/configure
WRKSRC=		${WRKDIR}/${DISTNAME}/build

# Causes unaligned access fault...
# Note that the 32bit (sparc) binary works fine.
NOT_FOR_PLATFORM= NetBSD-*-sparc64

.include "../../mk/bsd.pkg.mk"
