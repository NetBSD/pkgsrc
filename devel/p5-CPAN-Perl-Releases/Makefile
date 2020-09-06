# $NetBSD: Makefile,v 1.77 2020/09/06 22:30:31 wiz Exp $

DISTNAME=	CPAN-Perl-Releases-5.20200820
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-Perl-Releases
COMMENT=	Mapping Perl releases on CPAN to the location of the tarballs
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CPAN/Perl/Releases/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
