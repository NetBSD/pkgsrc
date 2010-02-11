# $NetBSD: Makefile,v 1.13 2010/02/11 22:57:40 joerg Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdstat-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Analyze tcpdump output

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-*

WRKSRC=		${WRKDIR}/${DISTNAME}/tcpdstat

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdstat ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
