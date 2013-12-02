# $NetBSD: Makefile,v 1.13 2013/12/02 12:44:35 wiz Exp $

DISTNAME=	AutoLoader-5.74
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5aul
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AutoLoader/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AutoLoader/
COMMENT=	Perl automatic module loader
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/AutoLoader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
