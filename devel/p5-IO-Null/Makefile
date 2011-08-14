# $NetBSD: Makefile,v 1.14 2011/08/14 12:26:10 obache Exp $
#

DISTNAME=		IO-Null-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5inu
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Null/
COMMENT=		Perl module for null filehandles

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/Null/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
