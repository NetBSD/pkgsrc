# $NetBSD: Makefile,v 1.1.1.1 1997/10/23 20:18:01 agc Exp $
# New ports collection makefile for:	ssam
# Version required:			1.9
# Date created:				Thu Oct 23 21:00:32 BST 1997
# Whom:					Alistair Crooks (agc@netbsd.org)
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
