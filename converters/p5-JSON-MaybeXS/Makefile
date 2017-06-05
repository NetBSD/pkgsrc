# $NetBSD: Makefile,v 1.15 2017/06/05 14:22:21 ryoon Exp $

DISTNAME=	JSON-MaybeXS-1.003008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-MaybeXS/
COMMENT=	Use Cpanel::JSON::XS with a fallback to JSON::PP
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.21.5,p5-JSON-PP>=2.27300}:../../converters/p5-JSON-PP

PERL5_PACKLIST=		auto/JSON/MaybeXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
