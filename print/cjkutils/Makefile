# $NetBSD: Makefile,v 1.5 2015/04/25 12:14:16 markd Exp $

DISTNAME=	texlive-20140525-source
PKGNAME=	cjkutils-4.8.3
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	Utilities for CJK LaTeX

DEPENDS+=	tex-cjkutils>=4.8.3:../../print/tex-cjkutils

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/cjkutils

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/cjkutils

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib

INSTALL_TARGET=	install-exec-am install-man

.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
