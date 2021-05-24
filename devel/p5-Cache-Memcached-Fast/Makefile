# $NetBSD: Makefile,v 1.8 2021/05/24 19:50:12 wiz Exp $

DISTNAME=	Cache-Memcached-Fast-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

HOMEPAGE=	https://metacpan.org/release/Cache-Memcached-Fast
COMMENT=	Perl client for memcached, in C language
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Cache/Memcached/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
