# $NetBSD: Makefile,v 1.16 2019/06/30 20:15:30 nia Exp $
#

DISTNAME=	PHP-Serialization-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PHP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PHP-Serialization
COMMENT=	Perl 5 module providing PHP-like (de)serialization
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/PHP/Serialization/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
