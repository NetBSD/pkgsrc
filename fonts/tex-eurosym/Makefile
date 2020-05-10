# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:44 markd Exp $

DISTNAME=	eurosym
PKGNAME=	tex-${DISTNAME}-1.4
PKGREVISION=	2
CATEGORIES=	fonts
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}-20090910
TEXLIVE_REV=	17265

MAINTAINER=	nico@orgrim.net
COMMENT=	MetaFont and macros for Euro sign

TEX_MIXEDMAP_FILES+=	eurosym.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
