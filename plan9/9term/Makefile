# $NetBSD: Makefile,v 1.4 1998/01/16 08:42:22 hubertf Exp $
# New ports collection makefile for:    9term
# Version required:     1.6.3
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# FreeBSD Id: Makefile,v 1.5 1996/12/07 23:43:56 asami Exp
#

DISTNAME=       9term.1.6.3
PKGNAME=	9term-1.6.3
CATEGORIES=	plan9
MASTER_SITES=   ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=	erich@FreeBSD.org

# needs library and private header, but not during runtime
BUILD_DEPENDS=	${PORTSDIR}/plan9/sam/${WRKDIR:T}/libframe/libframe.a:${PORTSDIR}/plan9/sam

OPSYS!= 	uname -s
.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=	yes
.endif

MAN1=		9term.1

NO_WRKSUBDIR=	yes
MAKE_ENV+=	WRKDIR=${WRKDIR}

.include <bsd.port.mk>
