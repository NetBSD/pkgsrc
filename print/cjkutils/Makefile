# $NetBSD: Makefile,v 1.19 2026/04/03 03:29:02 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	cjkutils-4.8.5
PKGREVISION=	4
CATEGORIES=	print

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cjk
COMMENT=	Utilities for CJK LaTeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-cjkutils>=4.8.3:../../print/tex-cjkutils

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/cjkutils

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/cjkutils

CONFIGURE_ARGS+=	--with-system-kpathsea
INSTALL_TARGET=		install-exec-am install-man

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
