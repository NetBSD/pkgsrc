# $NetBSD: Makefile,v 1.1.1.1 2000/04/03 15:35:40 sakamoto Exp $
#

DISTNAME=	rbogl
PKGNAME=	ruby-gl-0.31
CATEGORIES=	graphics
MASTER_SITES=	http://www2.giganet.net/~yoshi/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www2.giganet.net/~yoshi/

DEPENDS+=	ruby-1.4.*:../../lang/ruby
DEPENDS+=	Mesa-*:../../graphics/Mesa

USE_X11=	yes
WRKSRC=		${WRKDIR}/ruby-gl
RUBY_VERSION=	1.4
PLIST_SUBST=	RUBY_VERSION=${RUBY_VERSION}

do-configure:
	(cd ${WRKSRC}; ruby extconf.rb)

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ruby/gl
	${INSTALL_DATA} ${WRKSRC}/sample/* ${PREFIX}/share/examples/ruby/gl

.include "../../mk/bsd.pkg.mk"
