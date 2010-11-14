# $NetBSD: Makefile,v 1.1.1.1 2010/11/14 20:42:57 sno Exp $
#

DISTNAME=		File-ConfigDir-0.004
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-p5-people@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-ShareDir/
COMMENT=		Get directories of configuration files
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/File/ConfigDir/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	p5-File-HomeDir>=0.50:../../devel/p5-File-HomeDir
DEPENDS+=	p5-List-MoreUtils>=0.22:../../devel/p5-List-MoreUtils

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
