# $NetBSD: Makefile,v 1.14 2005/03/24 21:12:58 wiz Exp $

DISTNAME=		splitvt-1.6.3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/console/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Run two shells in a split window/terminal

BUILD_TARGET=
CONFIGURE_SCRIPT=	./Configure
HAS_CONFIGURE=		yes
USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
