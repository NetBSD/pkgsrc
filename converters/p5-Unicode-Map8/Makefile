# $NetBSD: Makefile,v 1.6 2005/07/13 18:01:20 jlam Exp $
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

PERL5_PACKLIST=         auto/Unicode/Map8/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
