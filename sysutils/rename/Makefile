# $NetBSD: Makefile,v 1.3 2012/10/23 19:51:21 asau Exp $

DISTNAME=	rename-1.3
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rename/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rename.sourceforge.net/
COMMENT=	Rename recursively with regex patterns

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

BUILDLINK_TRANSFORM+=	opt:-O3:${CFLAGS}

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin &&		\
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 &&	\
	${INSTALL_PROGRAM} ${WRKSRC}/rename ${DESTDIR}${PREFIX}/bin &&	\
	${INSTALL_MAN} ${WRKSRC}/rename.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
