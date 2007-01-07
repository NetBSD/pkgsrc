# $NetBSD: Makefile,v 1.18 2007/01/07 09:14:01 rillig Exp $

DISTNAME=		splitvt-1.6.3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/console/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Run two shells in a split window/terminal

BUILD_TARGET=
CONFIGURE_SCRIPT=	./Configure
HAS_CONFIGURE=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
