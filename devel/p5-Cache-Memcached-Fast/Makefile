# $NetBSD: Makefile,v 1.5 2020/04/11 11:37:46 mef Exp $
#

DISTNAME=	Cache-Memcached-Fast-0.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

HOMEPAGE=	https://metacpan.org/release/Cache-Memcached-Fast
COMMENT=	Perl client for memcached, in C language
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Cache/Memcached/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
