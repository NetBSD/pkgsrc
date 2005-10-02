# $NetBSD: Makefile,v 1.1.1.1 2005/10/02 11:10:45 wiz Exp $
#
# In order to ensure compliance with U.S. and international law, please
# do not modify this file to provide pointers to the source or homepage
# for this software or submit any PRs telling us the contents of the
# HOMEPAGE or MASTER_SITES definitions in this Makefile.

DISTNAME=		clit18src
PKGNAME=		convertlit-1.8
CATEGORIES=		textproc
MASTER_SITES=		${CONVERTLIT_MASTER_SITES}
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		${CONVERTLIT_HOMEPAGE}
COMMENT=		Convert Microsoft Legal Reader format eBooks into open format

WRKSRC=			${WRKDIR}/clit18
BUILD_DIRS=		${WRKDIR}/lib ${WRKSRC}
MAKEFILE=		makefile
USE_TOOLS+=		gmake

RESTRICTED=		Possible legal problems
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clit ${PREFIX}/bin/convertlit

.include "../../math/ltm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
