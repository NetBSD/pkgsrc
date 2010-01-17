# $NetBSD: options.mk,v 1.4 2010/01/17 17:38:17 sno Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Module-Build

PKG_SUPPORTED_OPTIONS=	dist_authoring license_creation ppm_support bundling
PKG_SUGGESTED_OPTIONS=	# empty - only for CPAN Authors

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdist_authoring)
DEPENDS+=	{perl>=5.10.0,p5-Archive-Tar>=1.09}:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-Pod-Readme>=0.04:../../textproc/p5-Pod-Readme
DEPENDS+=	p5-Module-Signature>=0.21:../../security/p5-Module-Signature
.endif
.if !empty(PKG_OPTIONS:Mlicense_creation)
DEPENDS+=	p5-Software-License-[0-9]*:../../devel/p5-Software-License
.endif
.if !empty(PKG_OPTIONS:Mppm_support)
DEPENDS+=	{perl>=5.10.1,p5-IO>=1.13}:../../devel/p5-IO
.endif
.if !empty(PKG_OPTIONS:Mbundling)
# contains required ExtUtils::Installed>=1.999_001
DEPENDS+=	{perl>=5.10.1,p5-ExtUtils-Install>=1.54}:../../devel/p5-ExtUtils-Install
.endif
