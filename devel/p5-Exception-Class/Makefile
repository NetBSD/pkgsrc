# $NetBSD: Makefile,v 1.47 2022/06/28 11:32:21 wiz Exp $

DISTNAME=	Exception-Class-1.45
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exception/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Exception-Class
COMMENT=	Perl5 module implementing real exception classes
LICENSE=	artistic-2.0

DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Devel-StackTrace>=1.20:../../devel/p5-Devel-StackTrace

USE_LANGUAGES=		# none
PERL5_PACKLIST=		auto/Exception/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
