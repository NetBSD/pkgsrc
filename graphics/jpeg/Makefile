# $NetBSD: Makefile,v 1.6 1998/04/15 10:38:26 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1997/07/17 15:12:43 max Exp
#

DISTNAME=       jpegsrc.v6a
PKGNAME=        jpeg-6a
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=	packages@netbsd.org

WRKSRC=         ${WRKDIR}/jpeg-6a
GNU_CONFIGURE=	yes
INSTALL_TARGET= install install-lib
MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
