# $NetBSD: Makefile,v 1.15 2017/06/05 14:24:09 ryoon Exp $

DISTNAME=	Math-Base85-0.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Base85/
COMMENT=	Perl extension for base 85 numbers, as referenced by RFC 1924
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Math/Base85/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
