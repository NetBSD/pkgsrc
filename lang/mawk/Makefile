# $NetBSD: Makefile,v 1.11 2003/09/05 19:00:59 tron Exp $
#

DISTNAME=       mawk-1.3.3
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.whidbey.net/pub/brennan/ \
		ftp://ftp.fu-berlin.de/unix/languages/mawk/

MAINTAINER=	agc@NetBSD.org
COMMENT=	Mike Brennan's fast awk clone

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=              CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
