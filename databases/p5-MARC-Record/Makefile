# $NetBSD: Makefile,v 1.4 2010/08/21 16:33:02 seb Exp $

DISTNAME=		MARC-Record-2.0.0
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MARC-Record/
COMMENT=		MARC record handling package
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/MARC/Record/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
