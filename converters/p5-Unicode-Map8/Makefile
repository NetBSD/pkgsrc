# $NetBSD: Makefile,v 1.1.1.1 2004/11/02 23:40:10 seb Exp $
#

DISTNAME=	Unicode-Map8-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.unicode.org/
COMMENT=	Perl5 module providing mapping tables between charsets

DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String

USE_BUILDLINK3=		yes
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Unicode/Map8/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
