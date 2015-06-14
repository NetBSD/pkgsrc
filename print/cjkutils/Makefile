# $NetBSD: Makefile,v 1.6 2015/06/14 12:50:00 markd Exp $

DISTNAME=	texlive-20150521-source
PKGNAME=	cjkutils-4.8.4
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	Utilities for CJK LaTeX

DEPENDS+=	tex-cjkutils>=4.8.3:../../print/tex-cjkutils

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/cjkutils

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/cjkutils

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea

INSTALL_TARGET=	install-exec-am install-man

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
