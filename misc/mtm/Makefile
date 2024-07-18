# $NetBSD: Makefile,v 1.1 2024/07/18 13:25:36 ktnb Exp $

DISTNAME=	mtm-1.2.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=deadpixi/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/deadpixi/mtm/
COMMENT=	The Micro Terminal Multiplexer
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/mtm/terminfo

LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncurses}/lib
LDFLAGS+=	-L${BUILDLINK_PREFIX.ncurses}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtm ${DESTDIR}/${PREFIX}/bin && \
	${INSTALL_MAN} ${WRKSRC}/mtm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/mtm.ti ${DESTDIR}${PREFIX}/share/mtm/terminfo

# needs ncurses: wgetscrreg
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
