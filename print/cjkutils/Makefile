# $NetBSD: Makefile,v 1.1.1.1 2011/10/19 22:52:32 minskim Exp $

DISTNAME=	texlive-20110705-source
PKGNAME=	cjkutils-4.8.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	Utilities for CJK LaTeX

DEPENDS+=	tex-cjkutils-[0-9]*:../../print/tex-cjkutils

PKG_DESTDIR_SUPPORT=	user-destdir

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
