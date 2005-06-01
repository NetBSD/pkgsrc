# $NetBSD: Makefile,v 1.21 2005/06/01 18:02:57 jlam Exp $

DISTNAME=	rbogl-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-opengl-${VERSION}
PKGREVISION=	2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www2.giganet.net/~yoshi/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2.giganet.net/~yoshi/
COMMENT=	OpenGL/GLU/GLUT interface modules for Ruby

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/opengl-${VERSION}
VERSION=		0.32f
INSTALL_TARGET=		site-install
CONFIGURE_ARGS+=	--with-ruby-dir="${LOCALBASE}" \
			--with-x11-dir="${X11BASE}"

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
