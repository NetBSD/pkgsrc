# New ports collection makefile for: gd
# Version required:     1.2
# Date created:         28 Jan 1997
# Whom:                 jeff@cetlink.net
#
# $NetBSD: Makefile,v 1.2 1998/03/08 00:49:33 tron Exp $
# $FreeBSD Id: Makefile,v 1.2 1997/02/14 07:55:45 asami Exp
#

DISTNAME=       gd1.2
PKGNAME=        gd-1.2
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	packages@netbsd.org

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

.include <bsd.port.mk>
