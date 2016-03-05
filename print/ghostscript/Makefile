# $NetBSD: Makefile,v 1.105 2016/03/05 11:27:53 jperkin Exp $
#

# XXX The version number is the last one before the agpl change.
DISTNAME=	ghostscript-9.05
PKGREVISION=	8
CATEGORIES=	print meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package for installing the preferred ghostscript version

META_PACKAGE=	yes

PKG_OPTIONS_VAR=		PKG_OPTIONS.gs_type
PKG_OPTIONS_OPTIONAL_GROUPS=	ghostscript
PKG_OPTIONS_GROUP.ghostscript+=	ghostscript-agpl ghostscript-gpl
PKG_SUGGESTED_OPTIONS+=		ghostscript-gpl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mghostscript-agpl)
DEPENDS+=	ghostscript-agpl-[0-9]*:../../print/ghostscript-agpl
.elif !empty(PKG_OPTIONS:Mghostscript-gpl)
DEPENDS+=	ghostscript-gpl-[0-9]*:../../print/ghostscript-gpl
.endif

.include "../../mk/bsd.pkg.mk"
