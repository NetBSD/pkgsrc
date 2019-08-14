# $NetBSD: Makefile,v 1.39 2019/08/14 01:48:06 wen Exp $

DISTNAME=	Getopt-Long-Descriptive-0.104
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Getopt-Long-Descriptive
COMMENT=	Perl 5 module providing Getopt::Long with usage text
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Params-Validate>=0.97:../../devel/p5-Params-Validate
DEPENDS+=	p5-Sub-Exporter>=0.972:../../devel/p5-Sub-Exporter

#BUILD_DEPENDS+= {perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Warnings>=0.005:../../devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-CPAN-Meta-Check-[0-9]*:../../devel/p5-CPAN-Meta-Check

PERL5_PACKLIST=		auto/Getopt/Long/Descriptive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
