# $NetBSD: Makefile,v 1.5 2005/08/06 06:19:13 jlam Exp $
#

DISTNAME=	PAR-Dist-0.07
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5moi
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PAR/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PAR-Dist/
COMMENT=	Perl module toolkit to create and manipulate PAR distributions

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/PAR/Dist/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
