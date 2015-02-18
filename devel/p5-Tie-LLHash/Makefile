# $NetBSD: Makefile,v 1.8 2015/02/18 03:23:57 mef Exp $

DISTNAME=	Tie-LLHash-1.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-LLHash/
COMMENT=	Ordered hashes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Tie/LLHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
