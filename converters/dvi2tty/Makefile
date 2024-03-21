# $NetBSD: Makefile,v 1.25 2024/03/21 07:54:07 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	dvi2tty-6.0.2
PKGREVISION=	1
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Program for previewing DVI files
LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/dvi2tty

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvi2tty

CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-ptexenc

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/ptexenc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
