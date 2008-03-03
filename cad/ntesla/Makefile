# $NetBSD: Makefile,v 1.8 2008/03/03 01:50:26 jlam Exp $
#

DISTNAME=		ntesla-1.7
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/circuits/}

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.nic.funet.fi/pub/sci/electrical/tesla/
COMMENT=		Tesla coil design program

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntesla ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
