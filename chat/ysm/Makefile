# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/06/23 18:41:21 jlam Exp $
#

DISTNAME=	ysmv7_2_7_1
PKGNAME=	ysm-2.7.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ysmv7/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://ysmv7.sourceforge.net/
COMMENT=	The 'You Sick Me' terminal based ICQ client

MAKEFILE=	BSDmakefile

do-install:
	${CP} ${WRKSRC}/ysm ${PREFIX}/bin/ysm
	${CP} ${WRKSRC}/docs/ysm.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
