# $NetBSD: Makefile,v 1.2 2004/12/20 11:31:05 grant Exp $

DISTNAME=		Locale-Maketext-Simple-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Simple interface to Locale::Maketext::Lexicon

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/Maketext/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
