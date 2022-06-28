# $NetBSD: Makefile,v 1.19 2022/06/28 11:31:56 wiz Exp $

DISTNAME=	CLASS-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHWERN/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CLASS
COMMENT=	Alias for __PACKAGE__
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CLASS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
