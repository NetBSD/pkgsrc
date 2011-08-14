# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:46 obache Exp $

DISTNAME=	Tie-Cache-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5tca
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Cache/
COMMENT=	LRU Cache in Memory
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Tie/Cache/.packlist

REPLACE_PERL=	*.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
