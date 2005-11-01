# $NetBSD: Makefile,v 1.8 2005/11/01 19:23:23 tv Exp $

DISTNAME=	bridged-20010701
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Userland ethernet bridge daemon

NOT_FOR_PLATFORM=	Interix-*-* # no direct interface API

WRKSRC=		${WRKDIR}/bridged
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bridge ${PREFIX}/sbin/bridged

.include "../../mk/bsd.pkg.mk"
