# $NetBSD: Makefile,v 1.3 2001/02/16 15:22:33 wiz Exp $
#

DISTNAME=	rbogl
PKGNAME=	ruby-gl-0.31
CATEGORIES=	graphics
MASTER_SITES=	http://www2.giganet.net/~yoshi/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www2.giganet.net/~yoshi/
COMMENT=	Ruby interface to OpenGL

DEPENDS+=	ruby-1.4.*:../../lang/ruby

USE_X11=	yes
USE_MESA=	yes
WRKSRC=		${WRKDIR}/ruby-gl
RUBY_VERSION=	1.4
PLIST_SUBST=	RUBY_VERSION=${RUBY_VERSION}

do-configure:
	(cd ${WRKSRC}; ruby extconf.rb)

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ruby/gl
	${INSTALL_DATA} ${WRKSRC}/sample/* ${PREFIX}/share/examples/ruby/gl

.include "../../mk/bsd.pkg.mk"
