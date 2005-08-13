# $NetBSD: Makefile,v 1.1.1.1 2005/08/13 07:59:41 adrianp Exp $

DISTNAME=	Math-Base85-0.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Perl extension for base 85 numbers, as referenced by RFC 1924

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Math/Base85/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
