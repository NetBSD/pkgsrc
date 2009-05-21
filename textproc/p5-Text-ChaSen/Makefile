# $NetBSD: Makefile,v 1.16 2009/05/21 14:54:23 sno Exp $

DISTNAME=		Text-ChaSen-1.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tcs
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-ChaSen/
COMMENT=		Perl5 module to use ChaSen

USE_LANGUAGES=		c c++
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/ChaSen/.packlist

.include "../../textproc/chasen/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
