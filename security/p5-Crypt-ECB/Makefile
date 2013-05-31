# $NetBSD: Makefile,v 1.6 2013/05/31 12:41:53 wiz Exp $

DISTNAME=		Crypt-ECB-1.45
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		dsainty@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-ECB/
COMMENT=		Perl5 Electronic Codebook mode for various crypto algorithms

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/ECB/.packlist

LICENSE=		gnu-gpl-v2 # OR any later version

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
