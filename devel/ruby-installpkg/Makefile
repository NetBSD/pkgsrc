# $NetBSD: Makefile,v 1.5 2005/03/06 17:19:06 taca Exp $

DISTNAME=	installpkg-0.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.aracnet.com/~ptkwt/ruby_stuff/InstallPkg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	# not available
COMMENT=	Ruby module for writing install.rb files

RUBY_VERSION=		${RUBY16_VERSION}
USE_RUBY_INSTALL=	yes
NO_BUILD=		yes
INSTALL_TARGET=		# empty

post-extract:
	${RM} -f ${WRKSRC}/lib/.install-pkg.rb.swp

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
