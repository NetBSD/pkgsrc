# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:57 tv Exp $
# FreeBSD: ports/graphics/ruby-opengl/Makefile,v 1.4 2000/09/26 08:01:58 knu Exp

DISTNAME=	rbogl-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}opengl-${VERSION:S/c$/.3/}
PKGREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www2.giganet.net/~yoshi/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2.giganet.net/~yoshi/
COMMENT=	OpenGL/GLU/GLUT interface modules for Ruby

WRKSRC=		${WRKDIR}/opengl-${VERSION}
VERSION=	0.32c
DIST_SUBDIR=	ruby
USE_BUILDLINK3=	yes
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

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
