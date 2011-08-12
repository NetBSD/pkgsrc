# $NetBSD: Makefile,v 1.7 2011/08/12 17:02:29 taca Exp $

DISTNAME=	mini_magick-3.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/mini-magick/
COMMENT=	Ruby wrapper for ImageMagick command line
LICENSE=	mit

# MiniMagick uses identify(1) and mogrify(1) from ImageMagick.
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	${RUBY_PKGPREFIX}-subexec>=0.1.0<0.2:../../devel/ruby-subexec

pre-configure:
	${RM} -f ${WRKSRC}/.gitignore
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
