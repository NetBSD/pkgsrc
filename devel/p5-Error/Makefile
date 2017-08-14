# $NetBSD: Makefile,v 1.39 2017/08/14 18:49:39 wiz Exp $

DISTNAME=	Error-0.17025
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Error/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Error/
COMMENT=	Perl extension module for try/throw/catch exception handling
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Error/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
