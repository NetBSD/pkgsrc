# $NetBSD: Makefile,v 1.11 2017/09/22 07:06:35 wiz Exp $

DISTNAME=	utilispc-1.13
PKGNAME=	utilisp-1.13
CATEGORIES=	lang
MASTER_SITES=	https://dell.tanaka.ecc.u-tokyo.ac.jp/~ktanaka/UtiLisp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gps.tanaka.ecc.u-tokyo.ac.jp/wadalabfont/pukiwiki.php?%5B%5BUtiLisp%2FC%5D%5D
COMMENT=	UTI Lisp

# severe 64-bit issues
NOT_FOR_PLATFORM=	${LP64PLATFORMS}
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
