# $NetBSD: Makefile,v 1.16 2005/06/17 03:50:22 jlam Exp $

DISTNAME=		splitvt-1.6.3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/console/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Run two shells in a split window/terminal

BUILD_TARGET=
CONFIGURE_SCRIPT=	./Configure
HAS_CONFIGURE=		yes
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
