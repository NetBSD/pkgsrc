# $NetBSD: Makefile,v 1.28 2026/08/16 15:24:31 wiz Exp $

DISTNAME=	Net-OAuth-0.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RR/RRWO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-OAuth
COMMENT=	Perl5 extension for OAuth protocol support
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor>=0.31:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.06:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Crypt-OpenSSL-RSA>=0.38:../../security/p5-Crypt-OpenSSL-RSA
DEPENDS+=	p5-URI>=5.15:../../www/p5-URI
DEPENDS+=	p5-libwww>=1:../../www/p5-libwww
DEPENDS+=	p5-Crypt-SysRandom>=0.006:../../security/p5-Crypt-SysRandom
TOOL_DEPENDS+=	p5-Test-Warn>=0.21:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/Net/OAuth/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
