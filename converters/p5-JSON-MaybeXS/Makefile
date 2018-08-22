# $NetBSD: Makefile,v 1.20 2018/08/22 09:43:07 wiz Exp $

DISTNAME=	JSON-MaybeXS-1.004000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-MaybeXS/
COMMENT=	Use Cpanel::JSON::XS with a fallback to JSON::PP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Cpanel-JSON-XS-[0-9]*:../../converters/p5-Cpanel-JSON-XS

PERL5_PACKLIST=		auto/JSON/MaybeXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
