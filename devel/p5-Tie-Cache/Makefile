# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:52 wiz Exp $

DISTNAME=	Tie-Cache-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5tca
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Cache/
COMMENT=	LRU Cache in Memory
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Tie/Cache/.packlist

REPLACE_PERL=	*.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
