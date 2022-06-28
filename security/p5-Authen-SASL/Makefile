# $NetBSD: Makefile,v 1.35 2022/06/28 11:35:39 wiz Exp $
#

DISTNAME=	Authen-SASL-2.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Authen-SASL
COMMENT=	Perl module to handle SASL authentication
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Authen/SASL/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Authen-SASL
PKG_SUPPORTED_OPTIONS=	gssapi
PKG_SUGGESTED_OPTIONS=	gssapi
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mgssapi)
DEPENDS+=	p5-GSSAPI-[0-9]*:../../security/p5-GSSAPI
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
