# $NetBSD: Makefile,v 1.8 2008/08/11 14:51:38 he Exp $

DISTNAME=	PerlIO-via-dynamic-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PerlIO-via-dynamic/
COMMENT=	Perl module for dynamic PerlIO layers

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/PerlIO/via/dynamic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
