# $NetBSD: Makefile,v 1.29 2023/07/06 09:38:42 wiz Exp $

DISTNAME=	Cache-Memcached-1.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Cache-Memcached
COMMENT=	Perl API for distributed memory cache daemon memcached
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-String-CRC32-[0-9]*:../../textproc/p5-String-CRC32
#DEPENDS+=	{perl>=5.10,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Cache/Memcached/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
