# $NetBSD: Makefile,v 1.28 2008/06/19 15:21:35 taca Exp $

DISTNAME=	ruby-opengl-0.60.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://ruby-opengl.rubyforge.org/
COMMENT=	Ruby bindings for OpenGL, GLU and GLUT

DEPENDS+=	rake>=0.8.1:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-mkrf>=0.2.0:../../devel/ruby-mkrf

.include "../../misc/rubygems/rubygem.mk"

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
