# $NetBSD: Makefile,v 1.2 2018/08/22 09:43:40 wiz Exp $
#

DISTNAME=	Cache-Memcached-Fast-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

HOMEPAGE=	http://search.cpan.org/dist/Cache-Memcached-Fast/
COMMENT=	Perl client for memcached, in C language
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Cache/Memcached/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
