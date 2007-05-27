# $NetBSD: Makefile,v 1.2 2007/05/27 20:47:07 heinz Exp $
#

DISTNAME=		File-HomeDir-0.64
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
