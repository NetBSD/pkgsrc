# $NetBSD: Makefile,v 1.126 2021/12/08 16:02:32 adam Exp $
#

# XXX The version number is the last one before the agpl change.
DISTNAME=	ghostscript-9.05
PKGREVISION=	27
CATEGORIES=	print meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package for installing the preferred ghostscript version

META_PACKAGE=	yes

PKG_OPTIONS_VAR=		PKG_OPTIONS.gs_type
PKG_OPTIONS_OPTIONAL_GROUPS=	ghostscript
PKG_OPTIONS_GROUP.ghostscript+=	ghostscript-agpl ghostscript-gpl
PKG_SUGGESTED_OPTIONS+=		ghostscript-agpl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mghostscript-agpl)
DEPENDS+=	ghostscript-agpl-[0-9]*:../../print/ghostscript-agpl
.elif !empty(PKG_OPTIONS:Mghostscript-gpl)
DEPENDS+=	ghostscript-gpl-[0-9]*:../../print/ghostscript-gpl
.endif

.include "../../mk/bsd.pkg.mk"
