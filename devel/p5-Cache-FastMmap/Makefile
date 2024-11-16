# $NetBSD: Makefile,v 1.36 2024/11/16 12:03:45 wiz Exp $

DISTNAME=	Cache-FastMmap-1.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Cache-FastMmap
COMMENT=	Shared memory cache through an mmap'ed file
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Cache/FastMmap/.packlist

TEST_DEPENDS+=		p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
