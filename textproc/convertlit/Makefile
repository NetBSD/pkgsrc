# $NetBSD: Makefile,v 1.6 2006/09/09 02:46:08 obache Exp $
#
# In order to ensure compliance with U.S. and international law, please
# do not modify this file to provide pointers to the source or homepage
# for this software or submit any PRs telling us the contents of the
# HOMEPAGE or MASTER_SITES definitions in this Makefile.

DISTNAME=		clit18src
PKGNAME=		convertlit-1.8
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${CONVERTLIT_MASTER_SITES}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${CONVERTLIT_HOMEPAGE}
COMMENT=		Convert Microsoft Legal Reader format eBooks into open format

WRKSRC=			${WRKDIR}
BUILD_DIRS=		lib clit18
MAKE_FILE=		makefile
USE_TOOLS+=		gmake

SUBST_CLASSES+=		d2u
SUBST_STAGE.d2u=	pre-configure
SUBST_MESSAGE.d2u=	Stripping CRLF line ends.
SUBST_FILES.d2u+=		*.h *.c */*.h */*.c */*/*.h */*/*.c
SUBST_FILTER_CMD.d2u=	${TR} -d '\r'

RESTRICTED=		Possible legal problems
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clit18/clit ${PREFIX}/bin/convertlit

.include "../../math/ltm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
