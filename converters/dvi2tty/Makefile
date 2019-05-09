# $NetBSD: Makefile,v 1.20 2019/05/09 09:47:34 adam Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	dvi2tty-6.0.0
PKGREVISION=	3
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
