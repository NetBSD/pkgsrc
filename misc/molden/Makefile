# $NetBSD: Makefile,v 1.20 2006/10/04 21:49:19 wiz Exp $

DISTNAME=	molden4.2
PKGNAME=	${DISTNAME:S/molden/&-/}
PKGREVISION=	1
CATEGORIES=	misc # chemistry
MASTER_SITES=	ftp://ftp.cmbi.kun.nl/pub/molgraph/molden/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.cmbi.ru.nl/molden/molden.html
COMMENT=	Displaying MOLecular DENsity

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_FILE=	makefile
BUILD_TARGET=	molden

USE_LANGUAGES=		c fortran

INTERACTIVE_STAGE=	fetch

LICENSE=	molden-license
RESTRICTED=	Redistributing Molden by unregistered user is prohibited.
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}

FETCH_MESSAGE=								\
	"Please read the following to learn how to get a copy of Molden:" \
	""								\
	"    http://www.cmbi.kun.nl/molden/howtoget.html"	\
	""								\
	"Then put the file:"						\
	"    ${DISTNAME}${EXTRACT_SUFX}"				\
	"into"								\
	"    ${DISTDIR}"						\

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/molden ${PREFIX}/bin/
	for d in doc test utils ; do \
		${INSTALL_DATA_DIR} ${PREFIX}/share/molden/$${d} ; \
		for f in ${WRKSRC}/$${d}/* ; do \
			${INSTALL_DATA} $${f} ${PREFIX}/share/molden/$${d} ; \
		done ; \
	done

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
