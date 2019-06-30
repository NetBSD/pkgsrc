# $NetBSD: Makefile,v 1.16 2019/06/30 20:16:18 nia Exp $
#

DISTNAME=	Math-Base36-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-Base36
COMMENT=	Perl 5 module to encode and decode base36 strings
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Math/Base36/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
