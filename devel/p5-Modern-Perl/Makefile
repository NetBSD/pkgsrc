# $NetBSD: Makefile,v 1.27 2020/04/16 10:53:10 mef Exp $

DISTNAME=	Modern-Perl-1.20200211
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CH/CHROMATIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Modern-Perl
COMMENT=	Enable all of the features of Modern Perl with one command
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Modern/Perl/.packlist

PERL5_REQD+=		5.10.0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
