# $NetBSD: Makefile,v 1.28 2022/06/28 11:33:12 wiz Exp $

DISTNAME=	Set-Object-1.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
