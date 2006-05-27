# $NetBSD: Makefile,v 1.6 2006/05/27 02:55:38 wiz Exp $
#

DISTNAME=		Locale-Maketext-Fuzzy-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		dieter.NetBSD@pandora.be
COMMENT=		Maketext from already interpolated strings

DEPENDS+=		{perl>=5.8.0,p5-Locale-Maketext-[0-8]*}:../../misc/p5-Locale-Maketext

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Locale/Maketext/Fuzzy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
