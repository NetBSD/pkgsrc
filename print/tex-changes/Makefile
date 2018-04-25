# $NetBSD: Makefile,v 1.1 2018/04/25 11:00:45 markd Exp $

DISTNAME=	changes
PKGNAME=	tex-${DISTNAME}-2.0.4
TEXLIVE_REV=	41737

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/changes
COMMENT=	Manual change markup
LICENSE=	lppl-1.3c

DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-truncate-[0-9]*:../../print/tex-truncate
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xifthen-[0-9]*:../../devel/tex-xifthen
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

REPLACE_BASH+=	${WRKSRC}/scripts/changes/delcmdchanges.bash
USE_TOOLS+=	bash:run

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
