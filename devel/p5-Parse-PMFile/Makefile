# $NetBSD: Makefile,v 1.6 2020/08/31 18:08:40 wiz Exp $

DISTNAME=	Parse-PMFile-0.42
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parse-PMFile
COMMENT=	Parses .pm files as PAUSE does
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-CPANfile-[0-9]*:../../devel/p5-Module-CPANfile
DEPENDS+=	p5-ExtUtils-MakeMaker-CPANfile-[0-9]*:../../devel/p5-ExtUtils-MakeMaker-CPANfile

PERL5_PACKLIST=	auto/Parse/PMFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
