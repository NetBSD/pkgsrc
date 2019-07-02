# $NetBSD: Makefile,v 1.20 2019/07/02 07:47:18 wen Exp $

DISTNAME=	JSON-PP-4.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/JSON-PP
COMMENT=	JSON::XS compatible pure-Perl module
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/JSON/PP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
