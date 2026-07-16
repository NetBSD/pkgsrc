# $NetBSD: Makefile,v 1.41 2026/07/16 19:04:18 wiz Exp $

DISTNAME=	Business-ISBN-Data-20240523.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Business-ISBN-Data
COMMENT=	Data for the p5-Business-ISBN package
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Business/ISBN/Data/.packlist
REPLACE_PERL+=	make_data.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
