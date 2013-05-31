# $NetBSD: Makefile,v 1.10 2013/05/31 12:41:56 wiz Exp $
#

DISTNAME=		Mozilla-CA-20130114
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mozilla/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Mozilla-CA/
COMMENT=		Mozilla's CA cert bundle for Perl
LICENSE=		mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Mozilla/CA/.packlist
REPLACE_PERL+=		mk-ca-bundle.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
