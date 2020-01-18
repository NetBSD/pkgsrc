# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:02 rillig Exp $

DISTNAME=	easy-todo
PKGNAME=	tex-${DISTNAME}-20140101
TEXLIVE_REV=	32677

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/easy-todo
COMMENT=	To-do notes in a document
LICENSE=	apache-2.0

DEPENDS+=	tex-tocloft-[0-9]*:../../print/tex-tocloft

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
