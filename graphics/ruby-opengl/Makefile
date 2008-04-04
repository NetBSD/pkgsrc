# $NetBSD: Makefile,v 1.27 2008/04/04 15:19:23 jlam Exp $

DISTNAME=	ruby-opengl-0.60.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://ruby-opengl.rubyforge.org/
COMMENT=	Ruby bindings for OpenGL, GLU and GLUT

DEPENDS+=	rake>=0.8.1:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-mkrf>=0.2.0:../../devel/ruby-mkrf

.include "../../misc/rubygems/rubygem.mk"

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
