# $NetBSD: Makefile,v 1.8 2005/07/13 18:01:34 jlam Exp $
#

DISTNAME=		Geography-Countries-1.4
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5gcn
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geography/}

MAINTAINER=		gson@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Geography-Countries/
COMMENT=		Perl5 module for mapping contry names and codes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geography/Countries/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
