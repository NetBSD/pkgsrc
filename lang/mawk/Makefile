# $NetBSD: Makefile,v 1.14 2004/04/07 19:10:16 reed Exp $
#

DISTNAME=       mawk-1.3.3
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.whidbey.net/pub/brennan/ \
		ftp://ftp.fu-berlin.de/unix/languages/mawk/

MAINTAINER=	agc@NetBSD.org
COMMENT=	Mike Brennan's fast awk clone

INSTALLATION_DIRS=	man/man1

GNU_CONFIGURE=	yes
TEST_TARGET=	mawk_test fpe_test

.include "../../mk/bsd.prefs.mk"

# mawk configure fails with -ffast-math
CFLAGS:=	${CFLAGS:S/-ffast-math//}

.if ${OPSYS} == "SunOS"
MAKE_ENV+=              CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
