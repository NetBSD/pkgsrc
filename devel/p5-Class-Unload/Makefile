# $NetBSD: Makefile,v 1.9 2014/06/09 18:44:05 schmonz Exp $

DISTNAME=	Class-Unload-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Unload/
COMMENT=	Perl 5 module to unload a class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector

PERL5_PACKLIST=		auto/Class/Unload/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
