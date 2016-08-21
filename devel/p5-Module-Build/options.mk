# $NetBSD: options.mk,v 1.8 2016/08/21 07:14:14 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Module-Build

PKG_SUPPORTED_OPTIONS=	p5-module-build-dist-authoring p5-module-build-license-creation
PKG_SUGGESTED_OPTIONS=	# empty - only for CPAN Authors

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mp5-module-build-dist-authoring)
#DEPENDS+=	{perl>=5.10.0,p5-Archive-Tar>=1.09}:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-Pod-Readme>=0.04:../../textproc/p5-Pod-Readme
DEPENDS+=	p5-Module-Signature>=0.21:../../security/p5-Module-Signature
.endif
.if !empty(PKG_OPTIONS:Mp5-module-build-license-creation)
DEPENDS+=	p5-Software-License-[0-9]*:../../devel/p5-Software-License
.endif
