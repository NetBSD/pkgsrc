# $NetBSD: Makefile,v 1.4 2001/09/09 20:36:44 agc Exp $
#

DISTNAME=	hugelatex-1.0
CATEGORIES=	print
MASTER_SITES=	# none
DISTFILES=	# nada

MAINTAINER=	hubertf@netbsd.org
COMMENT=	LaTeX format files with large limits

DEPENDS+=	teTeX-1.0*:../teTeX

EXTRACT_ONLY=	# nothing
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

TEXMF_CNF=	${LOCALBASE}/share/texmf/web2c/texmf.cnf

do-install:
	${CP} -p ${TEXMF_CNF} ${TEXMF_CNF}-before-hugelatex
	${CAT} ${FILESDIR}/texmf.cnf-add >>${TEXMF_CNF}
	cd `dirname ${TEXMF_CNF}`; \
	echo "" | ${PREFIX}/bin/latex -ini -fmt=hugelatex -progname=hugelatex latex.ini || ${TRUE}; \
	${RM} -f texsys.aux
	${RM} -f ${PREFIX}/bin/hugelatex
	${LN} -s latex ${PREFIX}/bin/hugelatex
	${PREFIX}/bin/mktexlsr

.include "../../mk/bsd.pkg.mk"
