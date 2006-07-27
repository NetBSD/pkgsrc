# $NetBSD: Makefile,v 1.19 2006/07/27 00:09:06 hubertf Exp $
#

DISTNAME=	hugelatex-2.0
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	# none
DISTFILES=	# nada

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	LaTeX format files with large limits

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# nothing
NO_CHECKSUM=	yes
NO_BUILD=	yes

TEXMF_CNF=	${PKG_TEXMFPREFIX}/web2c/texmf.cnf

.include "../../print/teTeX/module.mk"

do-install:
	${CP} -p ${TEXMF_CNF} ${TEXMF_CNF}-before-hugelatex
	${CAT} ${FILESDIR}/texmf.cnf-add >>${TEXMF_CNF}
	cd `dirname ${TEXMF_CNF}`; \
	${MV} latex.fmt latex.fmt.BAK || ${TRUE} ; \
	${ECHO} "" | ${PREFIX}/bin/latex -ini -fmt=hugelatex -progname=hugelatex latex.ini || ${TRUE}; \
	${MV} latex.fmt hugelatex.fmt ; \
	${MV} latex.log hugelatex.log ; \
	${MV} latex.fmt.BAK latex.fmt || ${TRUE} ; \
	${RM} -f texsys.aux
	${RM} -f ${PREFIX}/bin/hugelatex
	${LN} -s latex ${PREFIX}/bin/hugelatex

.include "../../mk/bsd.pkg.mk"
