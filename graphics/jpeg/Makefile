# New ports collection makefile for:	jpeg
# Version required:     6a
# Date created:		6 November 1994
# Whom:			smace
#
# $NetBSD: Makefile,v 1.3 1998/01/24 05:22:28 hubertf Exp $
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
	${LDCONFIG} -m ${PREFIX}/lib || /usr/bin/true

.include <bsd.port.mk>
