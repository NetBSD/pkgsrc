# $NetBSD: Makefile,v 1.5 2016/06/08 19:24:21 wiz Exp $
#

DISTNAME=	Crypt-URandom-0.36
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Crypt-URandom/
COMMENT=	Perl5 module to provide non blocking randomness
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Crypt/URandom/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
