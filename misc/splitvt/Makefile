# $NetBSD: Makefile,v 1.19.6.1 2008/07/25 09:48:35 rtr Exp $

DISTNAME=		splitvt-1.6.6
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/console/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Run two shells in a split window/terminal

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=
HAS_CONFIGURE=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
