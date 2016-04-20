# $NetBSD: Makefile,v 1.9 2016/04/20 14:42:27 mef Exp $

DISTNAME=	Config-Grammar-1.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Grammar/
COMMENT=	Grammar-based, user-friendly config parser
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Config/Grammar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
