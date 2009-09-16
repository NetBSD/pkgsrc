# $NetBSD: Makefile,v 1.19 2009/09/16 18:34:31 sno Exp $

DISTNAME=	Event-1.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5eve
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPRIT/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Event/
COMMENT=	Event library for Perl
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Event/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
