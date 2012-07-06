# $NetBSD: Makefile,v 1.26 2012/07/06 13:05:33 sno Exp $

DISTNAME=	Filter-1.45
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fil
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Filter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Filter/
COMMENT=	Perl5 classes representing a number of source filters
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Filter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
