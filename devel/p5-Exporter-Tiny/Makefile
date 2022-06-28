# $NetBSD: Makefile,v 1.17 2022/06/28 11:32:22 wiz Exp $

DISTNAME=	Exporter-Tiny-1.002002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Exporter-Tiny
COMMENT=	Exporter with the features of Sub::Exporter but only core dependencies
LICENSE=	gnu-gpl-v1 OR artistic

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Exporter/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
