# New ports collection makefile for:	xmcd
# Version required:	2.2
# Date created:		16 Februar 1995
# Whom:			Gennady Sorokopud <gena@NetVision.net.il>
#
# $NetBSD: Makefile,v 1.2 1997/10/29 01:18:30 augustss Exp $
# FreeBSD Id: Makefile,v 1.8 1997/09/08 13:20:10 tg Exp 
#

DISTNAME=	xmcd-2.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/xmcd

MAINTAINER=	deischen@iworks.InterWorks.org

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
IS_INTERACTIVE=	yes	# asks a lot of questions

post-install:
	${CP} ${WRKSRC}/README ${PREFIX}/lib/X11/xmcd

.include <bsd.port.mk>
