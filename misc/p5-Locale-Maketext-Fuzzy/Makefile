# $NetBSD: Makefile,v 1.1.1.1 2004/07/30 13:57:11 cube Exp $
#

DISTNAME=		Locale-Maketext-Fuzzy-0.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		dieter.NetBSD@pandora.be
COMMENT=		Maketext from already interpolated strings

DEPENDS+=		{perl>=5.8.0,perl-thread>=5.8.0,p5-Locale-Maketext-[0-8]*}:../../misc/p5-Locale-Maketext

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/Maketext/Fuzzy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
