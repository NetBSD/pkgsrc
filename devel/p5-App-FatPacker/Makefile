# $NetBSD: Makefile,v 1.17 2016/04/09 04:56:30 mef Exp $

DISTNAME=	App-FatPacker-0.010005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-FatPacker/
COMMENT=	Perl5 module to pack your dependencies onto your script file
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL+=		bin/fatpack

PERL5_PACKLIST=		auto/App/FatPacker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
