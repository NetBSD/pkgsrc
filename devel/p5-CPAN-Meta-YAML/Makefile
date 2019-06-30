# $NetBSD: Makefile,v 1.15 2019/06/30 20:14:35 nia Exp $

DISTNAME=	CPAN-Meta-YAML-0.018
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-Meta-YAML
COMMENT=	Perl module to read and write a subset of YAML for CPAN Meta files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CPAN/Meta/YAML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
