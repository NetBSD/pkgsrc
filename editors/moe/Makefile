# $NetBSD: Makefile,v 1.1 2024/03/21 00:07:27 nia Exp $

DISTNAME=	moe-1.14
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=moe/}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/moe/
COMMENT=	Modeless, user-friendly console text editor
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
INFO_FILES=	yes
USE_TOOLS+=	makeinfo
USE_LANGUAGES=	c c++

FAKE_NCURSES=	yes

EGDIR=		${PREFIX}/share/examples/moe
CONF_FILES=	${EGDIR}/moe.conf ${PKG_SYSCONFDIR}/moe.conf

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	CXX=${CXX:Q}
CONFIGURE_ARGS+=	CXXFLAGS=${CXXFLAGS:Q}
CONFIGURE_ARGS+=	CPPFLAGS=${CPPFLAGS:Q}
CONFIGURE_ARGS+=	LDFLAGS=${LDFLAGS:Q}
CONFIGURE_ARGS+=	LIBS=${LIBS:Q}
CONFIGURE_ARGS+=	MAKEINFO=${MAKEINFO}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGINFODIR}
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/moe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moe \
		${DESTDIR}${PREFIX}/bin/moe
	${INSTALL_DATA} ${WRKSRC}/doc/moe.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/moe.1
	${INSTALL_DATA} ${WRKSRC}/doc/moe.info \
		${DESTDIR}${PREFIX}/${PKGINFODIR}/moe.info
	${INSTALL_DATA} ${WRKSRC}/moe.conf \
		${DESTDIR}${PREFIX}/share/examples/moe/moe.conf

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
