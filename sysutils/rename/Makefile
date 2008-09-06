# $NetBSD: Makefile,v 1.2 2008/09/06 22:44:18 bjs Exp $

DISTNAME=	rename-1.3
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rename/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rename.sourceforge.net/
COMMENT=	Rename recursively with regex patterns

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

BUILDLINK_TRANSFORM+=	opt:-O3:${CFLAGS}

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin &&		\
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 &&	\
	${INSTALL_PROGRAM} ${WRKSRC}/rename ${DESTDIR}${PREFIX}/bin &&	\
	${INSTALL_MAN} ${WRKSRC}/rename.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
