# $NetBSD: Makefile,v 1.9 2006/03/04 21:30:17 jlam Exp $

DISTNAME=	bridged-20010701
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Userland ethernet bridge daemon

NOT_FOR_PLATFORM=	Interix-*-* # no direct interface API

WRKSRC=		${WRKDIR}/bridged
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bridge ${PREFIX}/sbin/bridged

.include "../../mk/bsd.pkg.mk"
