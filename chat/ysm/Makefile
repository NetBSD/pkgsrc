# $NetBSD: Makefile,v 1.8 2004/03/29 08:06:18 xtraeme Exp $

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
USE_BUILDLINK3=	YES

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
