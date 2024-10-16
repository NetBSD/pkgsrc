# $NetBSD: Makefile,v 1.1 2024/10/16 02:36:37 markd Exp $

DISTNAME=	greek-fontenc
PKGNAME=	tex-${DISTNAME}-2.6
TEXLIVE_REV=	68877

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/greek-fontenc
COMMENT=	LICR macros and encoding definition files for Greek
LICENSE=	lppl-1.3c AND 2-clause-bsd

CHECK_INTERPRETER_SKIP+=	share/texmf-dist/tex/latex/greek-fontenc/lgr2licr.lua

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
