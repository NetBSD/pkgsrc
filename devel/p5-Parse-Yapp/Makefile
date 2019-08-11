# $NetBSD: Makefile,v 1.35 2019/08/11 13:20:09 wiz Exp $
#

DISTNAME=	Parse-Yapp-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parse-Yapp
COMMENT=	Perl5 LALR parser
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Parse/Yapp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
