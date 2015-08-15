# $NetBSD: Makefile,v 1.5 2015/08/15 12:47:46 mef Exp $

DISTNAME=	Devel-FindPerl-0.014
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-FindPerl/
COMMENT=	Perl 5 module providing the path of the running perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-Config>=0.007:../../devel/p5-ExtUtils-Config

BUILD_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/Devel/FindPerl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
