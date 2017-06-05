# $NetBSD: Makefile,v 1.7 2017/06/05 14:22:57 ryoon Exp $

DISTNAME=	ExtUtils-MakeMaker-Coverage-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://cpan.metacpan.org/authors/id/S/SM/SMPETERS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/S/SM/SMPETERS/
COMMENT=	Add a Makefile target to determine test coverage using Devel::Cover
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Object-Accessor-[0-9]*:../../devel/p5-Object-Accessor

PERL5_PACKLIST=	auto/ExtUtils/MakeMaker/Coverage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
