# New ports collection makefile for:	xmcd
# Version required:	2.2 (pl1)
# Date created:		21 December 1997
# Whom:			hubertf@netbsd.org
#
# $NetBSD: Makefile,v 1.3 1997/12/21 02:11:55 hubertf Exp $
# FreeBSD Id: Makefile,v 1.8 1997/09/08 13:20:10 tg Exp 
#

DISTNAME=	xmcd-2.2
PKGNAME=	xmcd-2.2pl1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.netcom.com/pub/tk/tkan/xmcd-2.2/src/

MAINTAINER=	hubertf@netbsd.org

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
IS_INTERACTIVE=	yes	# asks a lot of questions

post-install:
	${CP} ${WRKSRC}/README ${PREFIX}/lib/X11/xmcd
	${MV} ${PREFIX}/man/cat1/xmcd.1 ${PREFIX}/man/man1/xmcd.1
	${MV} ${PREFIX}/man/cat1/cda.1 ${PREFIX}/man/man1/cda.1
	${MV} ${PREFIX}/man/cat1/wm2xmcd.1 ${PREFIX}/man/man1/wm2xmcd.1

.include <bsd.port.mk>
