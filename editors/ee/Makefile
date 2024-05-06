# $NetBSD: Makefile,v 1.6 2024/05/06 08:40:24 jperkin Exp $

DISTNAME=	ee-1.5.2.src
PKGNAME=	${DISTNAME:S,.src,,}
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://mirrors.ustc.edu.cn/gentoo/distfiles/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.ucl.ac.uk/~ccaabaa/is/unix/ee.htm
COMMENT=	EasyEdit, a classic curses text editor
LICENSE=	2-clause-bsd

MAKE_ENV+=	CFLAGS=${CFLAGS:Q}
MAKE_ENV+=	LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=	${WRKDIR}/easyedit-${PKGVERSION_NOREV}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}					\
	${MAKE_PROGRAM:Q} ${MAKE_FLAGS} all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ee ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ee.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
