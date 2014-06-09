# $NetBSD: Makefile,v 1.14 2014/06/09 19:11:31 schmonz Exp $

DISTNAME=	UNIVERSAL-require-0.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEILB/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=UNIVERSAL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-require/
COMMENT=	Perl module to require() from a variable
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/UNIVERSAL/require/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
