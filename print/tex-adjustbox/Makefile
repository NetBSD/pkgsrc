# $NetBSD: Makefile,v 1.11 2023/04/01 10:08:03 markd Exp $

DISTNAME=	adjustbox
PKGNAME=	tex-${DISTNAME}-1.3a
TEXLIVE_REV=	64967

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/adjustbox
COMMENT=	Graphics package-alike macros for "general" boxes
LICENSE=	lppl-1.3c

DEPENDS+=	tex-collectbox-[0-9]*:../../print/tex-collectbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
