# New ports collection makefile for:	joe
# Version required:	2.8
# Date created:		01 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# Imported into NetBSD by explorer@flame.org
#
# $NetBSD: Makefile,v 1.4 1998/04/07 13:04:21 tv Exp $
# FreeBSD Id: Makefile,v 1.3 1996/11/17 07:01:28 obrien Exp
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	explorer@netbsd.org

ALL_TARGET=	joe
WRKSRC=		${WRKDIR}/joe
MAN1=		joe.1

CFLAGS+=	-DTERMINFO

.include <bsd.port.mk>
