# $NetBSD: Makefile,v 1.1 2022/04/18 03:35:47 markd Exp $

DISTNAME=	sidenotes
PKGNAME=	tex-${DISTNAME}-1.00a
TEXLIVE_REV=	54524

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/sidenotes
COMMENT=	Typeset notes containing rich content, in the margin
LICENSE=	lppl-1.3c

DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-marginnote-[0-9]*:../../print/tex-marginnote

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
