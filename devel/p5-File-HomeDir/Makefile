# $NetBSD: Makefile,v 1.3 2007/06/09 23:18:25 abs Exp $
#

DISTNAME=		File-HomeDir-0.65
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://search.cpan.org/dist/File-HomeDir/
COMMENT=		Get the home directory for yourself or other users

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/File/HomeDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
