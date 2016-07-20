# $NetBSD: Makefile,v 1.1 2016/07/20 12:51:25 mef Exp $

DISTNAME=	MooX-ClassAttribute-0.011
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/T/TO/TOBYINK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/T/TO/TOBYINK/
COMMENT=	Declare class attributes Moose-style... but without Moose
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+= p5-MooseX-ClassAttribute-[0-9]*:../../devel/p5-MooseX-ClassAttribute

PERL5_PACKLIST= auto/MooX/ClassAttribute/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
