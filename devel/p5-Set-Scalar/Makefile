# $NetBSD: Makefile,v 1.9 2005/08/06 06:19:13 jlam Exp $
#

DISTNAME=	Set-Scalar-1.17
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ssc
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?dist=Set-Scalar
COMMENT=	Perl5 module for basic set operations

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Set/Scalar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
