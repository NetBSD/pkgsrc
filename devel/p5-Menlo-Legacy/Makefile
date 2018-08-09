# $NetBSD: Makefile,v 1.1 2018/08/09 11:45:48 jperkin Exp $

DISTNAME=	Menlo-Legacy-1.9022
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Menlo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Menlo-Legacy
COMMENT=	Legacy internal and client support for Menlo
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Menlo-[0-9]*:../../devel/p5-Menlo

PERL5_PACKLIST=	auto/Menlo/Legacy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
