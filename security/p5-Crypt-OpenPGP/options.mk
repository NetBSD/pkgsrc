# $NetBSD: options.mk,v 1.1 2010/02/12 18:26:36 sno Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Crypt-OpenPGP
PKG_SUPPORTED_OPTIONS=	pgp2-compat
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpgp2-compat)
DEPENDS+=		p5-Crypt-IDEA-[0-9]*:../../security/p5-Crypt-IDEA
DEPENDS+=		{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
.endif
