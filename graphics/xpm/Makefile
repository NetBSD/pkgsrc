# New ports collection makefile for:	xpm
# Version required:     3.4j
# Date created:		14 September 1994
# Whom:			jkh
#
# FreeBSD Id: Makefile,v 1.14 1997/07/17 15:12:45 max Exp
#

DISTNAME=       xpm-3.4j
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

USE_IMAKE=	yes

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
