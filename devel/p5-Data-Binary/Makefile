# $NetBSD: Makefile,v 1.1 2019/01/26 08:08:41 wen Exp $

DISTNAME=	Data-Binary-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Binary/
COMMENT=	Simple detection of binary versus text in strings
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Data/Binary/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
