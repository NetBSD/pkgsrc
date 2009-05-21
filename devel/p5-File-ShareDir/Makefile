# $NetBSD: Makefile,v 1.3 2009/05/21 14:28:44 tonnerre Exp $
#

DISTNAME=		File-ShareDir-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-p5-people@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-ShareDir/
COMMENT=		Get a generic path to the share directory

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/File/ShareDir/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		p5-Params-Util>=0.07:../../devel/p5-Params-Util
DEPENDS+=		p5-Class-Inspector>=1.12:../../devel/p5-Class-Inspector

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
