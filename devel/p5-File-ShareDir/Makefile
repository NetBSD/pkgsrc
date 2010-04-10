# $NetBSD: Makefile,v 1.5 2010/04/10 07:29:05 seb Exp $
#

DISTNAME=		File-ShareDir-1.02
PKGNAME=		p5-${DISTNAME}
#PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-p5-people@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-ShareDir/
COMMENT=		Get a generic path to the share directory
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/File/ShareDir/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		p5-Class-Inspector>=1.12:../../devel/p5-Class-Inspector

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
