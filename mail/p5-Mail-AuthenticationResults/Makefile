# $NetBSD: Makefile,v 1.5 2020/08/31 18:10:03 wiz Exp $

DISTNAME=	Mail-AuthenticationResults-1.20200331.1
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
