# $NetBSD: Makefile,v 1.1.1.1 2001/06/30 15:09:33 taca Exp $
# FreeBSD: ports/graphics/ruby-opengl/Makefile,v 1.4 2000/09/26 08:01:58 knu Exp

DISTNAME=	rbogl-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}opengl-${VERSION}
CATEGORIES=	graphics
MASTER_SITES=	http://www2.giganet.net/~yoshi/
EXTRACT_SUFX=	.tgz

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www2.giganet.net/~yoshi/
COMMENT=	OpenGL/GLU/GLUT interface modules for Ruby

VERSION=	0.32a
DIST_SUBDIR=	ruby
USE_MESA=	yes
USE_X11=	yes
USE_RUBY_EXTCONF= yes

WRKSRC=		${WRKDIR}/opengl

CONFIGURE_ARGS+= --with-ruby-dir="${LOCALBASE}" \
		 --with-x11-dir="${X11BASE}"
INSTALL_TARGET=	site-install

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/opengl
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/opengl
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/opengl/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_DOCDIR}/opengl
	${INSTALL_DATA} ${WRKSRC}/README.EUC ${RUBY_DOCDIR}/opengl/ja

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
