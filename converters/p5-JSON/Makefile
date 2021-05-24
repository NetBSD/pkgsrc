# $NetBSD: Makefile,v 1.42 2021/05/24 19:49:21 wiz Exp $

DISTNAME=	JSON-4.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/JSON
COMMENT=	Perl module converts between JSON and Perl data structure
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/JSON/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
