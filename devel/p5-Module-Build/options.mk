# $NetBSD: options.mk,v 1.3 2009/06/13 06:46:45 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Module-Build

PKG_SUPPORTED_OPTIONS=	archive-tar module-signature pod-readme
PKG_SUPPORTED_OPTIONS+=	extutils-parsexs extutils-cbuilder extutils-install
PKG_SUPPORTED_OPTIONS+=	yaml version
PKG_SUGGESTED_OPTIONS=	archive-tar extutils-cbuilder extutils-parsexs
PKG_SUGGESTED_OPTIONS+=	pod-readme yaml version

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Marchive-tar)
DEPENDS+=	p5-Archive-Tar>=1.08:../../archivers/p5-Archive-Tar
.endif
.if !empty(PKG_OPTIONS:Myaml)
BUILD_DEPENDS+=	p5-YAML>=0.50:../../textproc/p5-YAML
.endif
.if !empty(PKG_OPTIONS:Mmodule-signature)
DEPENDS+=	p5-Module-Signature>=0.55:../../security/p5-Module-Signature
.endif
.if !empty(PKG_OPTIONS:Mextutils-parsexs)
DEPENDS+=	p5-ExtUtils-ParseXS>=1.02:../../devel/p5-ExtUtils-ParseXS
.endif
.if !empty(PKG_OPTIONS:Mextutils-cbuilder)
DEPENDS+=	p5-ExtUtils-CBuilder>=0.15:../../devel/p5-ExtUtils-CBuilder
.endif
.if !empty(PKG_OPTIONS:Mextutils-install)
DEPENDS+=	p5-ExtUtils-Install>=0.30:../../devel/p5-ExtUtils-Install
.endif
.if !empty(PKG_OPTIONS:Mpod-readme)
DEPENDS+=	p5-Pod-Readme>=0.04:../../textproc/p5-Pod-Readme
.endif
.if !empty(PKG_OPTIONS:Mversion)
DEPENDS+=	p5-version>=0.74:../../devel/p5-version
.endif
