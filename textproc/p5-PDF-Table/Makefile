# $NetBSD: Makefile,v 1.22 2019/09/18 14:29:41 wen Exp $

DISTNAME=	PDF-Table-0.11.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PDF-Table
COMMENT=	Utility class for building table layouts in a Perl5 PDF::API2 object
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PDF-API2>=2.019:../../textproc/p5-PDF-API2

PERL5_PACKLIST=	auto/PDF/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
