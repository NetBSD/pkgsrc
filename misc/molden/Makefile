# $NetBSD: Makefile,v 1.11 2005/01/12 15:32:01 jlam Exp $

DISTNAME=	molden4.2
PKGNAME=	${DISTNAME:S/molden/&-/}
CATEGORIES=	misc # chemistry
MASTER_SITES=	ftp://ftp.cmbi.kun.nl/pub/molgraph/molden/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.cmbi.kun.nl/~schaft/molden/molden.html
COMMENT=	Displaying MOLecular DENsity

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKEFILE=	makefile
BUILD_TARGET=	molden

USE_BUILDLINK3=		yes
USE_X11=		# defined
USE_LANGUAGES=		fortran

INTERACTIVE_STAGE=	fetch

LICENSE=	molden-license
RESTRICTED=	"Redistributing Molden by unregistered user is prohibited."
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}

_FETCH_MESSAGE=	\
	${ECHO} "======================================================================"; \
	${ECHO} " Please read the WWW page below to know how to get a copy of Molden."; \
	${ECHO} ; \
	${ECHO} "     http://www.cmbi.kun.nl/~schaft/molden/howtoget.html"; \
	${ECHO} ; \
	${ECHO} " Then put the file ${DISTNAME}${EXTRACT_SUFX} into ${DISTDIR}."; \
	${ECHO} "======================================================================"

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
.include "../../mk/bsd.pkg.mk"
