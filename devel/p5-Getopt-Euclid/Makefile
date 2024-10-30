# $NetBSD: Makefile,v 1.29 2024/10/30 08:05:30 wen Exp $

DISTNAME=	Getopt-Euclid-0.4.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Getopt-Euclid
COMMENT=	Perl 5 module to create command-line parser from documentation
LICENSE=	${PERL5_LICENSE}

DEPENDS=	p5-Pod-Parser>=0:../../textproc/p5-Pod-Parser

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Getopt/Euclid/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
