# $NetBSD: Makefile,v 1.10 2004/01/20 12:18:17 agc Exp $
# FreeBSD: ports/graphics/ruby-opengl/Makefile,v 1.4 2000/09/26 08:01:58 knu Exp

DISTNAME=	rbogl-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}opengl-${VERSION:S/c$/.3/}
CATEGORIES=	graphics
MASTER_SITES=	http://www2.giganet.net/~yoshi/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2.giganet.net/~yoshi/
COMMENT=	OpenGL/GLU/GLUT interface modules for Ruby

WRKSRC=		${WRKDIR}/opengl-${VERSION}
VERSION=	0.32c
DIST_SUBDIR=	ruby
USE_BUILDLINK2=	yes
USE_X11=	yes
USE_RUBY_EXTCONF= yes

CONFIGURE_ARGS+= --with-ruby-dir="${LOCALBASE}" \
		 --with-x11-dir="${X11BASE}"
INSTALL_TARGET=	site-install

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/opengl
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/opengl
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/opengl
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_DOCDIR}/opengl
	${INSTALL_DATA} ${WRKSRC}/README.EUC ${RUBY_DOCDIR}/opengl/README.ja

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
