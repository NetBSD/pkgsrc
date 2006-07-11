# $NetBSD: Makefile,v 1.1 2006/07/11 05:03:11 rillig Exp $
#

DISTNAME=	compiler-1.0
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Tests whether the pkgsrc compilers work as expected

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}
USE_TOOLS+=	printf

SRC_CMD=	${PRINTF} '\#if defined(__cplusplus)\nLANG: Cplus\n\#else\nLANG: Cplain\n\#endif\n'

do-build:
	# Test whether CPP is a C preprocessor.
	${SRC_CMD} | ${CPP} -DLANG=Cplain
	# Test whether CXXCPP is a C++ preprocessor.
	# CXXCPP is not (yet)? defined.
	#${SRC_CMD} | ${CXXCPP} -DLANG=Cplus

.include "../../mk/bsd.pkg.mk"
