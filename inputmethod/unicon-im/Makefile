# $NetBSD: Makefile,v 1.21 2026/01/04 10:47:27 wiz Exp $

DISTNAME=	unicon-1.2
PKGNAME=	unicon-im-1.2
PKGREVISION=	5
CATEGORIES=	inputmethod
# The site points at a parking domain.  Let it fall back to NetBSD
#MASTER_SITES=	http://www.opencjk.org/~yumj/download/

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=	http://www.opencjk.org/~yumj/project-chinput.html
COMMENT=	Libraries and modules of Unicon

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=0
CFLAGS+=	-Wno-incompatible-pointer-types

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

.include "../../devel/pth/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
