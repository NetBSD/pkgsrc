# $NetBSD: Makefile,v 1.11 2023/07/06 09:38:42 wiz Exp $

DISTNAME=	Cache-Memcached-Fast-0.27
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
