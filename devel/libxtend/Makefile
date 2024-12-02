# $NetBSD: Makefile,v 1.17 2024/12/02 07:52:50 nia Exp $

DISTNAME=	libxtend-0.2.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	5f45f635517a1877166ab1a7ca8a73d841b666bb

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/libxtendc
COMMENT=	Miscellaneous functions to extend libc
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
BUILD_TARGET=	apple
INSTALL_TARGET=	apple-install
.else
INSTALL_TARGET=	install-strip
.endif

LDFLAGS.SunOS+=	-lresolv

MAKE_ENV+=	DYLIB_PATH=${PREFIX}/lib MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
