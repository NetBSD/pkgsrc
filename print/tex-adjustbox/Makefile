# $NetBSD: Makefile,v 1.12 2025/05/09 22:28:19 markd Exp $

DISTNAME=	adjustbox
PKGNAME=	tex-${DISTNAME}-1.3c
TEXLIVE_REV=	74309

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/adjustbox
COMMENT=	Graphics package-alike macros for "general" boxes
LICENSE=	lppl-1.3c

DEPENDS+=	tex-collectbox-[0-9]*:../../print/tex-collectbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
