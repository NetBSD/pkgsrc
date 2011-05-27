# $NetBSD: Makefile,v 1.9 2011/05/27 09:43:20 obache Exp $
#

DISTNAME=	utilispc-1.13
PKGNAME=	utilisp-1.13
CATEGORIES=	lang
MASTER_SITES=	http://dell.tanaka.ecc.u-tokyo.ac.jp/UtiLisp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gps.tanaka.ecc.u-tokyo.ac.jp/wadalabfont/pukiwiki.php?%5B%5BUtiLisp%2FC%5D%5D
COMMENT=	UTI Lisp

PKG_DESTDIR_SUPPORT=	user-destdir

# severe 64-bit issues
NOT_FOR_PLATFORM=	${LP64PLATFORMS}
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
