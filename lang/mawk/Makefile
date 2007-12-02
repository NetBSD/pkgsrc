# $NetBSD: Makefile,v 1.20 2007/12/02 00:11:10 wiz Exp $
#

DISTNAME=	mawk-1.3.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/languages/mawk/

MAINTAINER=	agc@NetBSD.org
COMMENT=	Mike Brennan's fast awk clone

INSTALLATION_DIRS=	${PKGMANDIR}/man1

GNU_CONFIGURE=	yes
CONFIGURE_HAS_MANDIR=	no
TEST_TARGET=	mawk_test fpe_test
PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

# mawk configure fails with -ffast-math
CFLAGS:=	${CFLAGS:S/-ffast-math//}

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
