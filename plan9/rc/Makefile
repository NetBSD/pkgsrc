# $NetBSD: Makefile,v 1.3 1997/10/22 00:54:09 hubertf Exp $
# New ports collection makefile for:    rc
# Version required:     1.5b1
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# FreeBSD Id: Makefile,v 1.3 1996/11/12 02:19:38 obrien Exp
#

DISTNAME=       rc-1.5betadev-1
PKGNAME=	rc-1.5b1
CATEGORIES=	plan9
MASTER_SITES=   ftp://ftp.sys.toronto.edu/pub/rc/

MAINTAINER=	erich@FreeBSD.org

NO_WRKSUBDIR=	yes

OPSYS!=		uname -s
.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=	yes
.endif

MAN1=		rc.1 history.1
.include <bsd.port.mk>
