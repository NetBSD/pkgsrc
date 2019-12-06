# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:41 markd Exp $

DISTNAME=	verbatimbox
PKGNAME=	tex-${DISTNAME}-3.13
PKGREVISION=	1
TEXLIVE_REV=	33197

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Deposit verbatim text in a box
LICENSE=	lppl-1.3c

DEPENDS+=	tex-readarray-[0-9]*:../../print/tex-readarray

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
