# $NetBSD: Makefile,v 1.3 2002/06/13 08:34:01 martti Exp $
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
