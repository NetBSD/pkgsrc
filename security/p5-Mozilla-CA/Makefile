# $NetBSD: Makefile,v 1.3 2011/09/15 06:20:29 hiramatsu Exp $
#

DISTNAME=		Mozilla-CA-20110904
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mozilla/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Mozilla-CA/
COMMENT=		Mozilla's CA cert bundle for Perl
LICENSE=		mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Mozilla/CA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
