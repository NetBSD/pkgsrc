# $NetBSD: Makefile,v 1.27 2014/05/29 23:35:52 wiz Exp $

DISTNAME=	Event-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5eve
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPRIT/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Event/
COMMENT=	Event library for Perl
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Event/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
