# $NetBSD: Makefile,v 1.2 2022/12/18 14:53:07 taca Exp $

DISTNAME=	manpages-0.6.1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bitboxer/manpages
COMMENT=	Adds support for man pages to rubygems
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_MANPAGES=	no

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing man path.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/rubygems/commands/manpages_command.rb
SUBST_FILES.path+=	lib/rubygems_plugin.rb
SUBST_VARS.path+=	PKGMANDIR

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
