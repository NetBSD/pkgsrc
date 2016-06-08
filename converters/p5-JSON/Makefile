# $NetBSD: Makefile,v 1.27 2016/06/08 19:22:20 wiz Exp $

DISTNAME=	JSON-2.90
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON/
COMMENT=	Perl module converts between JSON and Perl data structure
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/JSON/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
