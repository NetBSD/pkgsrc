# $NetBSD: Makefile,v 1.31 2017/06/17 13:09:33 mef Exp $
#

DISTNAME=	Parse-Yapp-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-Yapp/
COMMENT=	Perl5 LALR parser
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Parse/Yapp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
