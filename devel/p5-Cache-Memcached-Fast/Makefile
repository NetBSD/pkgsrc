# $NetBSD: Makefile,v 1.14 2025/04/25 07:44:05 wiz Exp $

DISTNAME=	Cache-Memcached-Fast-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

HOMEPAGE=	https://metacpan.org/release/Cache-Memcached-Fast
COMMENT=	Perl client for memcached, in C language
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Cache/Memcached/Fast/.packlist

# client.c:27:10: fatal error: parse_keyword.h: No such file or directory
MAKE_JOBS_SAFE=	no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
