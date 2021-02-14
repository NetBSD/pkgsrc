# $NetBSD: Makefile,v 1.7 2021/02/14 00:47:35 markd Exp $

DISTNAME=	tlshell
PKGNAME=	tex-${DISTNAME}-2020.57712
TEXLIVE_REV=	57712

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GUI frontend (tcl/tk-based) for tlmgr
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	wish:run

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	.*wish
REPLACE.wish.new=	${TOOLS_PATH.wish}
REPLACE_FILES.wish=	bin/tlshell

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/tlshell/tlshell.tcl ${WRKSRC}/bin/tlshell
	${RM} -rf ${WRKSRC}/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
