# $NetBSD: Makefile,v 1.1 2023/10/02 00:25:58 schmonz Exp $

DISTNAME=	Net-OAuth2-0.67
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Net::OAuth2
COMMENT=	OAuth 2.0 implementation in Perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww>=0:../../www/p5-libwww
DEPENDS+=	p5-Carp>=0:../../devel/p5-Carp
DEPENDS+=	p5-HTTP-Message>=0:../../www/p5-HTTP-Message
DEPENDS+=	p5-JSON-MaybeXS>=0:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-URI>=0:../../www/p5-URI

PERL5_PACKLIST=	auto/Net/OAuth2/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
