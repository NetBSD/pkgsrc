# $NetBSD: Makefile,v 1.1 2026/03/09 03:28:56 jnemeth Exp $

DISTNAME=	Pod-POM-View-Restructured-1.000003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	https://cpan.org/authors/id/A/AL/ALEXM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-POM-View-Restructured/
COMMENT=	Perl module to convert .pod files to .rst files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp>=0:../../devel/p5-Carp
DEPENDS+=	p5-Data-Dumper>=0:../../devel/p5-Data-Dumper
DEPENDS+=	p5-Getopt-Long>=0:../../devel/p5-Getopt-Long
DEPENDS+=	p5-Pod-POM>=0:../../textproc/p5-Pod-POM

PERL5_PACKLIST=	auto/Pod/POM/View/Restructured/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
