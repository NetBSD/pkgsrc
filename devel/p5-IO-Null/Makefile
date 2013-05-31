# $NetBSD: Makefile,v 1.17 2013/05/31 12:40:25 wiz Exp $
#

DISTNAME=		IO-Null-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
SVR4_PKGNAME=		p5inu
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Null/
COMMENT=		Perl module for null filehandles

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/Null/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
