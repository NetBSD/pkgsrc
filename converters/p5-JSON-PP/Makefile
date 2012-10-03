# $NetBSD: Makefile,v 1.3 2012/10/03 21:54:08 wiz Exp $

DISTNAME=	JSON-PP-2.27200 
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-PP/
COMMENT=	JSON::XS compatible pure-Perl module
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/JSON/PP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
