# $NetBSD: Makefile,v 1.3 2004/03/16 02:01:10 taca Exp $

DISTNAME=	installpkg-0.0.1
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.aracnet.com/~ptkwt/ruby_stuff/InstallPkg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	# not available
COMMENT=	Ruby module for writing install.rb files

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${RUBY} install.rb

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
