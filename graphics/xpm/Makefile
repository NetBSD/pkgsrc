# New ports collection makefile for:	xpm
# Version required:     3.4j
# Date created:		14 September 1994
# Whom:			jkh
#
# $NetBSD: Makefile,v 1.6 1998/02/02 08:10:58 hubertf Exp $
# FreeBSD Id: Makefile,v 1.14 1997/07/17 15:12:45 max Exp
#

DISTNAME=       xpm-3.4j
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

MAINTAINER=	packages@netbsd.org

USE_IMAKE=	yes

CAT1= 		sxpm.0

post-install:
	${LDCONFIG} -m ${PREFIX}/lib || ${TRUE}

.include <bsd.port.mk>
