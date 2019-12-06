# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:13 markd Exp $

DISTNAME=	context-annotation
PKGNAME=	tex-${DISTNAME}-2015	# actually 2013.05.27
TEXLIVE_REV=	36188

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-annotation
COMMENT=	Annotate text blocks
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
