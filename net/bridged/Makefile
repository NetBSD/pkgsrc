# $NetBSD: Makefile,v 1.2 2003/03/29 12:41:54 jmmv Exp $

DISTNAME=	bridged-20010701
WRKSRC=		${WRKDIR}/bridged
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	packages@netbsd.org
COMMENT=	userland ethernet bridge daemon

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bridge ${PREFIX}/sbin/bridged

.include "../../mk/bsd.pkg.mk"
