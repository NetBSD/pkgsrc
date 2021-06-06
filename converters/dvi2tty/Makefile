# $NetBSD: Makefile,v 1.22 2021/06/06 01:17:17 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	dvi2tty-6.0.0
PKGREVISION=	5
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
