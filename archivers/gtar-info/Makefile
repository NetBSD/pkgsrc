# $NetBSD: Makefile,v 1.34 2014/08/17 16:28:18 wiz Exp $

.include "../../archivers/gtar/Makefile.common"

PKGNAME=	${DISTNAME:S/tar/gtar-info/}
SVR4_PKGNAME=	gtari
COMMENT=	Info format documentation for the GNU tape archiver
LICENSE=	gnu-fdl-v1.1

NO_CONFIGURE=		yes
NO_BUILD=		yes
INFO_FILES=		yes

INSTALLATION_DIRS=	${PKGINFODIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tar.info ${DESTDIR}${PREFIX}/${PKGINFODIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tar.info-[0-9]* ${DESTDIR}${PREFIX}/${PKGINFODIR}

.include "../../mk/bsd.pkg.mk"
