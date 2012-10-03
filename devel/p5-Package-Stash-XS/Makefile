# $NetBSD: Makefile,v 1.3 2012/10/03 21:55:27 wiz Exp $

DISTNAME=	Package-Stash-XS-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Package/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Package-Stash-XS/
COMMENT=	Perl 5 module providing a better correct Package::Stash implementation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

USE_LANGUAGES=	c
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Package/Stash/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
