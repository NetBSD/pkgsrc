# $NetBSD: Makefile,v 1.12 2025/04/21 21:01:39 wiz Exp $

DISTNAME=	bridged-20010701
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Userland ethernet bridge daemon

WRKSRC=		${WRKDIR}/bridged
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bridge ${DESTDIR}${PREFIX}/sbin/bridged

.include "../../mk/bsd.pkg.mk"
