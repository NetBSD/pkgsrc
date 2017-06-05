# $NetBSD: Makefile,v 1.12 2017/06/05 14:22:37 ryoon Exp $

DISTNAME=	CLASS-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/MSCHWERN/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CLASS/
COMMENT=	Alias for __PACKAGE__
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CLASS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
