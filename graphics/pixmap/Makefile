# New ports collection makefile for:	pixmap
# Version required:	2.6
# Date created:		19 February 1995
# Whom:			jmz
#
# $NetBSD: Makefile,v 1.3 1998/01/30 13:57:15 agc Exp $
# FreeBSD: Makefile,v 1.8 1996/11/18 09:53:36 asami Exp
#

DISTNAME=	pixmap2.6
PKGNAME=	pixmap-2.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/pixmap

MAINTAINER=	jmz@FreeBSD.org

LIB_DEPENDS=	Xpm.4.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/pixmap
USE_IMAKE=	yes
CAT1=    pixmap.0

.include <bsd.port.mk>
