# $NetBSD: Makefile,v 1.21 2009/03/10 17:50:22 sno Exp $

DISTNAME=	Filter-1.36
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fil
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Filter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Filter/
COMMENT=	Perl5 classes representing a number of source filters

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Filter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
