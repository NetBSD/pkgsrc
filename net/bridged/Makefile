# $NetBSD: Makefile,v 1.10 2008/06/20 01:09:29 joerg Exp $

DISTNAME=	bridged-20010701
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Userland ethernet bridge daemon

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-* # no direct interface API

WRKSRC=		${WRKDIR}/bridged
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bridge ${DESTDIR}${PREFIX}/sbin/bridged

.include "../../mk/bsd.pkg.mk"
