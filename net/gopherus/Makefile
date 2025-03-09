# $NetBSD: Makefile,v 1.1 2025/03/09 08:49:48 wiz Exp $

DISTNAME=	gopherus-1.2.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gopherus/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gopherus.sourceforge.net/
COMMENT=	Lightweight ncurses-based Gopher client
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.lin

BINDIR=			${PREFIX}/bin
DOCDIR=			${PREFIX}/share/doc/gopherus
INSTALLATION_DIRS=	${BINDIR} ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gopherus ${DESTDIR}${BINDIR}
	${INSTALL_DATA} ${WRKSRC}/gopherus.txt ${DESTDIR}${DOCDIR}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
