# $NetBSD: Makefile,v 1.18 2017/06/05 14:23:34 ryoon Exp $

DISTNAME=	Set-Object-1.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-Object/
COMMENT=	Perl module to manage sets of objects
LICENSE=	artistic-2.0

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Set/Object/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
