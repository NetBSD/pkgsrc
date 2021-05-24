# $NetBSD: Makefile,v 1.29 2021/05/24 19:51:02 wiz Exp $

DISTNAME=	Modern-Perl-1.20200211
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
