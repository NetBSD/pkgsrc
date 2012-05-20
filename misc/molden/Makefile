# $NetBSD: Makefile,v 1.27 2012/05/20 06:45:54 marino Exp $

DISTNAME=	molden4.6
PKGNAME=	${DISTNAME:S/molden/&-/}
PKGREVISION=	1
CATEGORIES=	misc # chemistry
MASTER_SITES=	ftp://ftp.cmbi.kun.nl/pub/molgraph/molden/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cmbi.ru.nl/molden/molden.html
COMMENT=	Displaying MOLecular DENsity
LICENSE=	molden-license

RESTRICTED=	Redistributing Molden by unregistered user is prohibited.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

DIST_SUBDIR=		${PKGNAME_NOREV}
PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=	makefile
BUILD_TARGET=	molden

USE_LANGUAGES=		c fortran77

INSTALLATION_DIRS=	bin share/molden/doc share/molden/test share/molden/utils

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/molden ${DESTDIR}${PREFIX}/bin
	for d in doc test utils ; do \
		for f in ${WRKSRC}/$${d}/* ; do \
			${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/molden/$${d} ; \
		done ; \
	done

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
