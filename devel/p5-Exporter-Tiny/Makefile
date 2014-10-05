# $NetBSD: Makefile,v 1.3 2014/10/05 14:34:00 wiz Exp $

DISTNAME=	Exporter-Tiny-0.042
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Exporter-Tiny/
COMMENT=	Exporter with the features of Sub::Exporter but only core dependencies
LICENSE=	gnu-gpl-v1 OR artistic

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Exporter/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
