# New ports collection makefile for:	jpeg
# Version required:     6a
# Date created:		6 November 1994
# Whom:			smace
#
# FreeBSD Id: Makefile,v 1.14 1997/07/17 15:12:43 max Exp
#

DISTNAME=       jpegsrc.v6a
PKGNAME=        jpeg-6a
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/jpeg/

WRKSRC=         ${WRKDIR}/jpeg-6a
GNU_CONFIGURE=	yes
INSTALL_TARGET= install install-lib
MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
