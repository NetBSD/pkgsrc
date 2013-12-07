# $NetBSD: options.mk,v 1.6 2013/12/07 00:58:01 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Module-Build

PKG_SUPPORTED_OPTIONS=	dist_authoring license_creation
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
