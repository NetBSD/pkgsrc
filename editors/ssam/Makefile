# New ports collection makefile for:	ssam
# Version required:			1.9
# Date created:				Thu Oct 23 21:00:32 BST 1997
# Whom:					Alistair Crooks (agc@netbsd.org)
#
# $NetBSD: Makefile,v 1.2 1998/01/24 04:50:08 hubertf Exp $
#

DISTNAME=	ssam-1.9
CATEGORIES=	editors
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@netbsd.org

BUILD_DEPENDS=	${PREFIX}/lib/libutf.a:${PORTSDIR}/misc/libutf
RUN_DEPENDS=	${PREFIX}/etc/langcoll.utf:${PORTSDIR}/misc/libutf

MAN1=		ssam.1
GNU_CONFIGURE=	yes
ALL_TARGET=	tst

.include <bsd.port.mk>
