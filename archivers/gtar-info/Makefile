# $NetBSD: Makefile,v 1.33 2014/02/24 08:16:56 adam Exp $

DISTNAME=	tar-1.27.1
PKGNAME=	${DISTNAME:S/tar/gtar-info/}
SVR4_PKGNAME=	gtari
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=tar/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	Info format documentation for the GNU tape archiver
LICENSE=	gnu-fdl-v1.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=		yes
NO_BUILD=		yes
INFO_FILES=		yes

INSTALLATION_DIRS=	${PKGINFODIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tar.info ${DESTDIR}${PREFIX}/${PKGINFODIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tar.info-[0-9]* ${DESTDIR}${PREFIX}/${PKGINFODIR}

.include "../../mk/bsd.pkg.mk"
