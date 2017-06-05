# $NetBSD: Makefile,v 1.11 2017/06/05 14:23:27 ryoon Exp $
#

DISTNAME=	Params-Coerce-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Params/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Params-Coerce/
COMMENT=	Perl 5 module allowing classes to do coercion of parameters

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Params/Coerce/.packlist

DEPENDS+=	p5-Params-Util>=0.05:../../devel/p5-Params-Util

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
