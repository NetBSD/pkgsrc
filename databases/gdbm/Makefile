# New ports collection makefile for: gdbm
# Version required:	1.7.3
# Date created:		8 Apr 1996
# Whom:			Brent J. Nordquist <bjn@visi.com>
#
# $NetBSD: Makefile,v 1.1.1.1 1997/10/27 03:25:20 hubertf Exp $
# FreeBSD Id: Makefile,v 1.4 1997/01/28 08:11:23 asami Exp 
#

DISTNAME=          gdbm-1.7.3
CATEGORIES=        databases
MASTER_SITES=      ${MASTER_SITE_GNU}

MAINTAINER=        bjn@visi.com

GNU_CONFIGURE=     yes
MAKE_FLAGS=        CFLAGS="${CFLAGS}" LDFLAGS=-s -f
MAN3=		   gdbm.3

.include <bsd.port.mk>
