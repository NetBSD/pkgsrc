# $NetBSD: Makefile,v 1.7 2005/06/17 03:50:24 jlam Exp $

DISTNAME=	bridged-20010701
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Userland ethernet bridge daemon

WRKSRC=		${WRKDIR}/bridged
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bridge ${PREFIX}/sbin/bridged

.include "../../mk/bsd.pkg.mk"
