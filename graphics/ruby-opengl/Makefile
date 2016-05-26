# $NetBSD: Makefile,v 1.33 2016/05/26 17:08:57 taca Exp $

DISTNAME=	ruby-opengl-0.60.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://ruby-opengl.rubyforge.org/
COMMENT=	Ruby bindings for OpenGL, GLU and GLUT
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mkrf>=0.2.0:../../devel/ruby-mkrf

USE_RAKE=	YES
MAKE_ENV+=	LDSHARED=${COMPILER_RPATH_FLAG:Q}${X11BASE:Q}/lib

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
