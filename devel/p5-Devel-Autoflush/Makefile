# $NetBSD: Makefile,v 1.1 2009/03/01 23:03:16 sno Exp $
#

DISTNAME=	Devel-Autoflush-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Autoflush/
COMMENT=	Perl module to set autoflush from the command line

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Devel/Autoflush/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
