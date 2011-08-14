# $NetBSD: Makefile,v 1.4 2011/08/14 12:48:49 obache Exp $
#

DISTNAME=		Geography-Countries-2009041301
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5gcn
CATEGORIES=		geography perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geography/}

MAINTAINER=		gson@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Geography-Countries/
COMMENT=		Perl5 module for mapping country names and codes
LICENSE=		mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geography/Countries/.packlist

PREV_PKGPATH=		misc/p5-Geography-Countries

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
