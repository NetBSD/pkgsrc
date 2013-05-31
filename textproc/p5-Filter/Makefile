# $NetBSD: Makefile,v 1.29 2013/05/31 12:42:09 wiz Exp $

DISTNAME=	Filter-1.45
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5fil
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Filter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Filter/
COMMENT=	Perl5 classes representing a number of source filters
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Filter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
