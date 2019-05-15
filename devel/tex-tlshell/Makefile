# $NetBSD: Makefile,v 1.1 2019/05/15 08:39:05 markd Exp $

DISTNAME=	tlshell
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50776

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	texlive tcl shell
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
