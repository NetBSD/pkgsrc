# $NetBSD: Makefile,v 1.3 2003/06/02 01:18:02 jschauma Exp $

DISTNAME=	bridged-20010701
WRKSRC=		${WRKDIR}/bridged
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	userland ethernet bridge daemon

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bridge ${PREFIX}/sbin/bridged

.include "../../mk/bsd.pkg.mk"
