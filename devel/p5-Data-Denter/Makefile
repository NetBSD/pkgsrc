# $NetBSD: Makefile,v 1.15 2020/08/31 18:07:45 wiz Exp $

DISTNAME=	Data-Denter-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Denter
COMMENT=	(deprecated) alternative Perl 5 module to Data::Dumper and Storable

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Denter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
