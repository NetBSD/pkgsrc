# $NetBSD: Makefile,v 1.4 2017/09/06 16:49:23 wiz Exp $

DISTNAME=	eurosym
PKGNAME=	tex-${DISTNAME}-1.4
PKGREVISION=	1
CATEGORIES=	fonts
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}-20090910
TEXLIVE_REV=	17265

MAINTAINER=	nico@orgrim.net
COMMENT=	MetaFont and macros for Euro sign

TEX_MIXEDMAP_FILES+=	eurosym.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
