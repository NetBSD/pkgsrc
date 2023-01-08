# $NetBSD: Makefile,v 1.2.2.1 2023/01/08 15:57:24 bsiegert Exp $

DISTNAME=	manpages-0.6.1
PKGREVISION=	2
CATEGORIES=	misc

MAINTAINER=	taca@NetBSD.org
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
