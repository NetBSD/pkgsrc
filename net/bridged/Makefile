# $NetBSD: Makefile,v 1.4 2003/07/17 22:51:02 grant Exp $

DISTNAME=	bridged-20010701
WRKSRC=		${WRKDIR}/bridged
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	userland ethernet bridge daemon

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bridge ${PREFIX}/sbin/bridged

.include "../../mk/bsd.pkg.mk"
