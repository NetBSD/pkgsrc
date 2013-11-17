# $NetBSD: Makefile,v 1.3 2013/11/17 17:10:59 minskim Exp $

DISTNAME=	texlive-20130530-source
PKGNAME=	cjkutils-4.8.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	Utilities for CJK LaTeX

DEPENDS+=	tex-cjkutils>=4.8.3:../../print/tex-cjkutils

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
