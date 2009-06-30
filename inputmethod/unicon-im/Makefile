# $NetBSD: Makefile,v 1.18 2009/06/30 00:07:17 joerg Exp $

DISTNAME=	unicon-1.2
PKGNAME=	unicon-im-1.2
PKGREVISION=	5
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.opencjk.org/~yumj/download/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.opencjk.org/~yumj/project-chinput.html
COMMENT=	Libraries and modules of Unicon

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=0

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

.include "../../devel/pth/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
