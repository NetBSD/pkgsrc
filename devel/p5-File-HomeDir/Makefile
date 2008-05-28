# $NetBSD: Makefile,v 1.4 2008/05/28 21:54:19 abs Exp $
#

DISTNAME=		File-HomeDir-0.69
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://search.cpan.org/dist/File-HomeDir/
COMMENT=		Get the home directory for yourself or other users

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/File/HomeDir/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
