# $NetBSD: Makefile,v 1.20 2013/05/31 12:40:22 wiz Exp $

DISTNAME=	Getopt-Long-Descriptive-0.092
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Getopt-Long-Descriptive/
COMMENT=	Perl 5 module providing Getopt::Long with usage text
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Params-Validate>=0.97:../../devel/p5-Params-Validate
DEPENDS+=	p5-Sub-Exporter>=0.972:../../devel/p5-Sub-Exporter

BUILD_DEPENDS+= {perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Getopt/Long/Descriptive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
