# $NetBSD: Makefile,v 1.22 2026/08/04 20:29:02 wiz Exp $

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/pth/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
