# $NetBSD: Makefile,v 1.14 2017/06/05 14:22:53 ryoon Exp $

DISTNAME=	Devel-Size-0.80
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Size/
COMMENT=	Perl 5 module for finding the memory usage of variables
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Devel/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
