# $NetBSD: Makefile,v 1.4 2011/10/13 07:42:44 hiramatsu Exp $

DISTNAME=	Class-Load-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Load/
COMMENT=	Provide a working (require "Class::Name") and more
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-OptList-[0-9]*:../../devel/p5-Data-OptList
DEPENDS+=	p5-Module-Runtime>=0.009:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Package-Stash>=0.32:../../devel/p5-Package-Stash
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Class/Load/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
