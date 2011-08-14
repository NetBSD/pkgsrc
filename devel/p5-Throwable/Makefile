# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:45 obache Exp $

DISTNAME=	Throwable-0.102080
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5err
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Throwable/
COMMENT=	Perl 5 role for classes that can be thrown
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-StackTrace>=1.2100:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Moose>=0.87:../../devel/p5-Moose

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Throwable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
