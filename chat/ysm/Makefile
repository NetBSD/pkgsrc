# $NetBSD: Makefile,v 1.6 2003/05/02 11:54:08 wiz Exp $

DISTNAME=	ysmv7_2_8_1
PKGREVISION=	1
PKGNAME=	ysm-2.8.1
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
