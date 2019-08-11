# $NetBSD: Makefile,v 1.3 2019/08/11 13:21:35 wiz Exp $

DISTNAME=	Mail-AuthenticationResults-1.20180923
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mail-AuthenticationResults
COMMENT=	Object Oriented Authentication-Results Headers
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/Mail/AuthenticationResults/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
