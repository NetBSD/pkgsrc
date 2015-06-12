# $NetBSD: Makefile,v 1.9 2015/06/12 10:49:54 wiz Exp $

DISTNAME=	Tie-LLHash-1.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-LLHash/
COMMENT=	Ordered hashes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Tie/LLHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
