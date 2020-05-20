# $NetBSD: Makefile,v 1.32 2020/05/20 06:09:03 rillig Exp $
#

DISTNAME=	fasthenry-3.0-12Nov96
PKGNAME=	fasthenry-3.0.19961112
CATEGORIES=	cad
MASTER_SITES=	http://www.rle.mit.edu/cpg/codes/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	https://www.rle.mit.edu/cpg/research_codes.htm
COMMENT=	Three-dimensional inductance extraction program

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=			${WRKDIR}/fasthenry-3.0
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS+=	default

.include "../../mk/bsd.prefs.mk"

LIBS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
.if (${MACHINE_ARCH} == "alpha")
#
# optimized libffm (free fast math library)
#
.  include "../../math/libffm/buildlink3.mk"
DEPENDS+=	libffm-[0-9]*:../../math/libffm
LIBS+=		-lffm
.endif
LIBS+=		-lm
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

# contact.c: In function 'walk_along_edge':
# contact.c:1334:40: error: array subscript has type 'char' [-Werror=char-subscripts]
#    equiv_nodes_on_edge(cell->bndry.nodes[start_node], travel_dir,
#                                         ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.pkg.mk"
