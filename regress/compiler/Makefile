# $NetBSD: Makefile,v 1.2 2006/10/22 07:52:27 rillig Exp $
#

DISTNAME=	compiler-1.1
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Tests whether the pkgsrc compilers work as expected

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}
USE_TOOLS+=	printf

SRC_CMD=	${PRINTF} '\#if defined(__cplusplus)\nLANG: Cplus\n\#else\nLANG: Cplain\n\#endif\n'

do-extract:
	cd ${FILESDIR} && cp *.c ${WRKSRC}

do-build:
	# Test whether CPP is a C preprocessor.
	${SRC_CMD} | cpp -DLANG=Cplain
	# Test whether CXXCPP is a C++ preprocessor.
	# CXXCPP is not (yet)? defined.
	#${SRC_CMD} | cxxcpp -DLANG=Cplus
	# Test whether white-space is preserved in macro definitions.
	cd ${WRKSRC} && cc checklen.c -o checklen -DLEN=4 -DSPACES=\"\ \ \ \ \" && ./checklen
	cd ${WRKSRC} && cc checklen.c -o checklen -DLEN=4 -DSPACES=\""    \"" && ./checklen
	cd ${WRKSRC} && cc checklen.c -o checklen -DLEN=4 -DSPACES='"    "' && ./checklen
	# Test whether backslashes are preserved in macro definitions.
	cd ${WRKSRC} && cc -c checktype.c -DTYPE="unsigned long"
	cd ${WRKSRC} && cc -c checktype.c -DTYPE=unsigned\ long
	
.include "../../mk/bsd.pkg.mk"
