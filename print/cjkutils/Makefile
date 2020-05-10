# $NetBSD: Makefile,v 1.12 2020/05/10 03:56:38 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	cjkutils-4.8.4
PKGREVISION=	5
CATEGORIES=	print

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	https://cjk.ffii.org/
COMMENT=	Utilities for CJK LaTeX

DEPENDS+=	tex-cjkutils>=4.8.3:../../print/tex-cjkutils

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/cjkutils

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/cjkutils

CONFIGURE_ARGS+=	--with-system-kpathsea
INSTALL_TARGET=		install-exec-am install-man

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
