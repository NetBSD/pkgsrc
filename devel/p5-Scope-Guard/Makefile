# $NetBSD: Makefile,v 1.13 2015/09/06 06:34:40 mef Exp $

DISTNAME=	Scope-Guard-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Scope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Scope-Guard/
COMMENT=	Lexically scoped resource management

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Scope/Guard/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
