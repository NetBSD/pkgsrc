# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:29 obache Exp $
#

DISTNAME=	Parse-ExuberantCTags-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-ExuberantCTags/
COMMENT=	Efficiently parse exuberant ctags files
LICENSE=	(${PERL5_LICENSE}) AND public-domain

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Parse/ExuberantCTags/.packlist
USE_LANGUAGES=		c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
