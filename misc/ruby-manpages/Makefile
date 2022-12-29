# $NetBSD: Makefile,v 1.3 2022/12/29 16:21:35 taca Exp $

DISTNAME=	manpages-0.6.1
PKGREVISION=	1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bitboxer/manpages
COMMENT=	Adds support for man pages to rubygems
LICENSE=	mit

USE_LANGUAGES=	# none

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing man path.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/rubygems/commands/manpages_command.rb
SUBST_FILES.path+=	lib/rubygems_plugin.rb
SUBST_VARS.path+=	PKGMANDIR

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
