# $NetBSD: Makefile,v 1.2 2019/12/06 20:21:23 markd Exp $

DISTNAME=	filehook
PKGNAME=	tex-${DISTNAME}-0.5d
TEXLIVE_REV=	24280

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/filehook
COMMENT=	Hooks for input files
LICENSE=	lppl-1.3c

DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
