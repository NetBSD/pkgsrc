# $NetBSD: Makefile,v 1.24 2009/05/24 13:10:49 sno Exp $
#

DISTNAME=		Digest-SHA1-2.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sh2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-SHA1/
COMMENT=		Perl5 module for SHA1
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Digest>=1.00:../../security/p5-Digest

CONFLICTS+=		p5-Digest-MD5<=2.12

PERL5_PACKLIST=		auto/Digest/SHA1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
