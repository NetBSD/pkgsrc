# $NetBSD: Makefile,v 1.4 2005/02/19 19:25:24 wiz Exp $
#

DISTNAME=	Unicode-Map8-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unicode-Map8/
COMMENT=	Perl5 module providing mapping tables between charsets

DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String

USE_BUILDLINK3=		yes
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Unicode/Map8/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
