# $NetBSD: Makefile,v 1.7 2004/01/12 10:38:22 cjep Exp $

DISTNAME=	ysmv7_2_8_1
PKGNAME=	ysm-2.8.1
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ysmv7/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://ysmv7.sourceforge.net/
COMMENT=	The 'You Sick Me' terminal based ICQ client

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
