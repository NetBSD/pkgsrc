# $NetBSD: Makefile,v 1.5 2016/06/08 19:22:20 wiz Exp $

DISTNAME=	Data-Hexify-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jv/Data-Hexify/lib/Data/Hexify.pm
COMMENT=	Perl extension for hexdumping arbitrary data
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Data/Hexify/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
