# $NetBSD: Makefile,v 1.102 2014/01/01 19:47:30 christos Exp $
#

# XXX The version number is the last one before the agpl change.
DISTNAME=	ghostscript-9.05
PKGREVISION=	6
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

.if !empty(PKG_OPTIONS_VAR:Mghostscript-agpl)
DEPENDS+=	ghostscript-agpl-[0-9]*:../../print/ghostscript-agpl
.elif !empty(PKG_OPTIONS_VAR:Mghostscript-gpl)
DEPENDS+=	ghostscript-gpl-[0-9]*:../../print/ghostscript-gpl
.endif

.include "../../mk/bsd.pkg.mk"
