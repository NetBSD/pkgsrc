# $NetBSD: Makefile,v 1.12 2003/09/30 21:47:14 seb Exp $
#

DISTNAME=       mawk-1.3.3
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.whidbey.net/pub/brennan/ \
		ftp://ftp.fu-berlin.de/unix/languages/mawk/

MAINTAINER=	agc@NetBSD.org
COMMENT=	Mike Brennan's fast awk clone

GNU_CONFIGURE=	yes
TEST_TARGET=	mawk_test fpe_test

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=              CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
