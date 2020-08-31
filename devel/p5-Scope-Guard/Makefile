# $NetBSD: Makefile,v 1.19 2020/08/31 18:08:49 wiz Exp $

DISTNAME=	Scope-Guard-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Scope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Scope-Guard
COMMENT=	Lexically scoped resource management

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Scope/Guard/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
