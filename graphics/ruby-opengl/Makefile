# $NetBSD: Makefile,v 1.23 2005/12/05 23:55:09 rillig Exp $

DISTNAME=	rbogl-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-opengl-${VERSION}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www2.giganet.net/~yoshi/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2.giganet.net/~yoshi/
COMMENT=	OpenGL/GLU/GLUT interface modules for Ruby

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/opengl-${VERSION}
VERSION=		0.32g
INSTALL_TARGET=		site-install
CONFIGURE_ARGS+=	--with-ruby-dir=${LOCALBASE:Q} \
			--with-x11-dir=${X11BASE:Q}

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/opengl
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/opengl
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/opengl
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_DOCDIR}/opengl
	${INSTALL_DATA} ${WRKSRC}/README.EUC ${RUBY_DOCDIR}/opengl/README.ja

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
