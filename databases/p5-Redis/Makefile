# $NetBSD: Makefile,v 1.14 2016/02/23 02:27:18 wen Exp $

DISTNAME=	Redis-1.982
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Redis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Redis/
COMMENT=	Perl binding for Redis database
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Fatal>=0:../../devel/p5-Test-Fatal \
		p5-Test-Deep>=0:../../devel/p5-Test-Deep

DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-IO-Socket-Timeout>=0.32:../../net/p5-IO-Socket-Timeout

PERL5_PACKLIST=	auto/Redis/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
