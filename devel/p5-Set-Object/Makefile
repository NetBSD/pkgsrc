# $NetBSD: Makefile,v 1.25 2020/08/31 18:08:49 wiz Exp $

DISTNAME=	Set-Object-1.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Set-Object
COMMENT=	Perl module to manage sets of objects
LICENSE=	artistic-2.0

USE_LANGUAGES+=	c # As said c is set as default, but necessary
PERL5_PACKLIST=	auto/Set/Object/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
