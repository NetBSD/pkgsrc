# $NetBSD: Makefile,v 1.5 2003/07/21 17:10:25 martti Exp $

DISTNAME=	bridged-20010701
WRKSRC=		${WRKDIR}/bridged
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Userland ethernet bridge daemon

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bridge ${PREFIX}/sbin/bridged

.include "../../mk/bsd.pkg.mk"
