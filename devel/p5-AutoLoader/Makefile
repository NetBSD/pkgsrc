# $NetBSD: Makefile,v 1.12 2013/05/31 12:40:04 wiz Exp $

DISTNAME=	AutoLoader-5.72
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
