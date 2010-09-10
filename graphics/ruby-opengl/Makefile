# $NetBSD: Makefile,v 1.30 2010/09/10 06:51:52 taca Exp $

DISTNAME=	ruby-opengl-0.60.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://ruby-opengl.rubyforge.org/
COMMENT=	Ruby bindings for OpenGL, GLU and GLUT
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mkrf>=0.2.0:../../devel/ruby-mkrf

USE_RAKE=	YES

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
