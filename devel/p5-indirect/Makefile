# $NetBSD: Makefile,v 1.6 2015/09/06 10:42:57 mef Exp $

DISTNAME=	indirect-0.36
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/V/VP/VPIT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/indirect/
COMMENT=	Lexically warn about using the indirect method call syntax
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/indirect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
