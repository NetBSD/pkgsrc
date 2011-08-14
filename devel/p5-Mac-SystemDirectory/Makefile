# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:16 obache Exp $
#

DISTNAME=	Mac-SystemDirectory-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mac-SystemDirectory/
COMMENT=	Locate Mac OS X Standard System Directories
LICENSE=	${PERL5_LICENSE}

ONLY_FOR_PLATFORM=	Darwin-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

PERL5_PACKLIST=		auto/Mac/SystemDirectory/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
