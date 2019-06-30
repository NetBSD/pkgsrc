# $NetBSD: Makefile,v 1.51 2019/06/30 20:15:44 nia Exp $

DISTNAME=	Storable-3.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Storable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Storable
COMMENT=	Perl extension module for persistent data storage
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Storable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
