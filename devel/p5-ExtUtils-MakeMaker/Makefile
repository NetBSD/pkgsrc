# $NetBSD: Makefile,v 1.9 2008/12/30 15:03:03 he Exp $
#

DISTNAME=	ExtUtils-MakeMaker-6.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-MakeMaker/
COMMENT=	Write a Makefile for an extension module from a Makefile.PL

DEPENDS+=	p5-UNIVERSAL-isa>=0:../../devel/p5-UNIVERSAL-isa

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/ExtUtils/MakeMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
