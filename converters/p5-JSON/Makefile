# $NetBSD: Makefile,v 1.46 2023/05/20 06:19:48 wiz Exp $

DISTNAME=	JSON-4.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/JSON
COMMENT=	Perl module converts between JSON and Perl data structure
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/JSON/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
