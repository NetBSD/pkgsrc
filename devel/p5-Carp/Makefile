# $NetBSD: Makefile,v 1.12 2025/07/04 08:45:18 wiz Exp $

DISTNAME=	Carp-1.50
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Carp
COMMENT=	Alternative warn and die for modules
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Carp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
