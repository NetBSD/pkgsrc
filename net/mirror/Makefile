# New ports collection makefile for:	mirror
# Version required:	2.8
# Date created:		15 May 1995
# Whom:			torstenb
#
# $NetBSD: Makefile,v 1.1.1.1 1997/10/27 05:01:30 hubertf Exp $
# FreeBSD Id: Makefile,v 1.6 1996/12/01 01:22:54 obrien Exp 
#

DISTNAME=	mirror-2.8
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	torstenb@FreeBSD.ORG

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		mirror.1 mirrormaster.1

pre-install:
	${MKDIR} ${PREFIX}/lib/mirror

.include <bsd.port.mk>
