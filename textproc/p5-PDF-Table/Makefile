# $NetBSD: Makefile,v 1.14 2017/06/05 14:24:43 ryoon Exp $

DISTNAME=	PDF-Table-0.9.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-Table/
COMMENT=	Utility class for building table layouts in a Perl5 PDF::API2 object
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PDF-API2>=2.019:../../textproc/p5-PDF-API2

PERL5_PACKLIST=	auto/PDF/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
