# $NetBSD: Makefile,v 1.22 2022/06/28 11:35:12 wiz Exp $

DISTNAME=	Net-OAuth-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-OAuth
COMMENT=	Perl5 extension for OAuth protocol support
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor>=0.31:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.06:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Digest-HMAC>=1.01:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Digest-SHA1>=2.12:../../security/p5-Digest-SHA1
#DEPENDS+=	{perl>=5.10.1,p5-Encode>=2.35}:../../textproc/p5-Encode
DEPENDS+=	p5-URI>=1.36:../../www/p5-URI

BUILD_DEPENDS+=	p5-Test-Warn>=0.21:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/Net/OAuth/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
