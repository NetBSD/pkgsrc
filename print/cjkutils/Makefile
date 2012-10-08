# $NetBSD: Makefile,v 1.2 2012/10/08 13:45:36 asau Exp $

DISTNAME=	texlive-20110705-source
PKGNAME=	cjkutils-4.8.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	Utilities for CJK LaTeX

DEPENDS+=	tex-cjkutils-[0-9]*:../../print/tex-cjkutils

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/cjkutils

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/cjkutils

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib

INSTALL_TARGET=	install-exec-am install-man

.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
