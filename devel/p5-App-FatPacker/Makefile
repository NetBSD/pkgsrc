# $NetBSD: Makefile,v 1.24 2019/10/10 11:27:45 mef Exp $

DISTNAME=	App-FatPacker-0.010008
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/App-FatPacker
COMMENT=	Perl5 module to pack your dependencies onto your script file
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL+=		bin/fatpack

PERL5_PACKLIST=		auto/App/FatPacker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
