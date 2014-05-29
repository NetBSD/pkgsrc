# $NetBSD: Makefile,v 1.23 2014/05/29 23:37:41 wiz Exp $

DISTNAME=		Text-ChaSen-1.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
SVR4_PKGNAME=		p5tcs
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-ChaSen/
COMMENT=		Perl5 module to use ChaSen

USE_LANGUAGES=		c c++

PERL5_PACKLIST=		auto/Text/ChaSen/.packlist

.include "../../textproc/chasen/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
