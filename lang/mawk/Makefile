# $NetBSD: Makefile,v 1.7 2000/05/05 06:26:59 tron Exp $
#

DISTNAME=       mawk1.3.3
PKGNAME=        mawk-1.3.3
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.whidbey.net/pub/brennan/ \
		ftp://ftp.fu-berlin.de/pub/unix/languages/mawk/

MAINTAINER=	agc@netbsd.org

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=              CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
