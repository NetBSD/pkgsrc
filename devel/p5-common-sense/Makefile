# $NetBSD: Makefile,v 1.12 2012/10/03 21:55:51 wiz Exp $

DISTNAME=	common-sense-3.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/common-sense/
COMMENT=	Save a tree AND a kitten, use common::sense!
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/common/sense/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
