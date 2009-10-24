# $NetBSD: Makefile,v 1.1.1.1 2009/10/24 08:37:36 sno Exp $
#

DISTNAME=		Data-Peek-0.27
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Data-Peek/
COMMENT=		A collection of low-level debug functions
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Data/Peek/.packlist
MAKE_ENV+=              AUTOMATED_TESTING=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
