# $NetBSD: Makefile,v 1.5 1999/09/04 15:22:02 agc Exp $
#

DISTNAME=       mawk1.2.2
PKGNAME=        mawk-1.2.2
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.oxy.edu/public/

MAINTAINER=	agc@netbsd.org

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=              CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
