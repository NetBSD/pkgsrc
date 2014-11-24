# $NetBSD: Makefile,v 1.25 2014/11/24 14:15:20 mef Exp $
#

DISTNAME=	Font-TTF-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mhosken/Font-TTF/
COMMENT=	Perl module for TrueType font hacking
LICENSE=	artistic-2.0

DEPENDS+=		p5-IO-String>=0:../../devel/p5-IO-String

PERL5_PACKLIST=		auto/Font/TTF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
