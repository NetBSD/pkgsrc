# New ports collection makefile for:	xmcd
# Version required:	2.2 (pl1)
# Date created:		21 December 1997
# Whom:			hubertf@netbsd.org
#
# $NetBSD: Makefile,v 1.6 1998/03/20 08:43:44 mycroft Exp $
# FreeBSD Id: Makefile,v 1.8 1997/09/08 13:20:10 tg Exp 
#

DISTNAME=	xmcd-2.2
PKGNAME=	xmcd-2.2pl1
CATEGORIES=	audio
MASTER_SITES=	http://mercury.hypersurf.com/~amb/download/xmcd-2.2/src/

MAINTAINER=	hubertf@netbsd.org

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
IS_INTERACTIVE=	yes	# asks a lot of questions

CAT1=		xmcd.0 cda.0 wm2xmcd.0
MAN1=		xmcd.1 cda.1 wm2xmcd.1

post-install:
	@strip ${PREFIX}/bin/xmcd
	@strip ${PREFIX}/bin/cda
	@strip ${PREFIX}/bin/wm2xmcd
	${CP} ${WRKSRC}/README ${PREFIX}/lib/X11/xmcd
	${MV} ${PREFIX}/man/cat1/xmcd.1 ${PREFIX}/man/man1/xmcd.1
	${MV} ${PREFIX}/man/cat1/cda.1 ${PREFIX}/man/man1/cda.1
	${MV} ${PREFIX}/man/cat1/wm2xmcd.1 ${PREFIX}/man/man1/wm2xmcd.1

.include <bsd.port.mk>
