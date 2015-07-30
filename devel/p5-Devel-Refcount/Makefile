# $NetBSD: Makefile,v 1.1 2015/07/30 12:51:22 schmonz Exp $

DISTNAME=	Devel-Refcount-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Refcount/
COMMENT=	Perl 5 module to obtain the REFCNT value of a referent
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Devel/Refcount/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
