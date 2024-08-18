# $NetBSD: Makefile,v 1.6 2024/08/18 08:23:26 wen Exp $

DISTNAME=		PAR-Packer-1.063
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=PAR/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/dist/PAR-Packer
COMMENT=		Perl5 module to create stand-alone executables and archives
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-PAR-[0-9]*:../../devel/p5-PAR
DEPENDS+=		p5-Getopt-ArgvFile-[0-9]*:../../devel/p5-Getopt-ArgvFile

PERL5_PACKLIST=		auto/PAR/Packer/.packlist

MAKE_JOBS_SAFE=		no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
