# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:27 jlam Exp $
#

DISTNAME=	PAR-Dist-0.07
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5moi
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PAR/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PAR-Dist/
COMMENT=	Perl module toolkit to create and manipulate PAR distributions

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/PAR/Dist/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
