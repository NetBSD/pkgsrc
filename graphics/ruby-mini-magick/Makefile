# $NetBSD: Makefile,v 1.4 2010/09/10 06:51:03 taca Exp $

DISTNAME=	mini_magick-2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/mini-magick/
COMMENT=	Ruby wrapper for ImageMagick command line
LICENSE=	mit

# MiniMagick uses identify(1) and mogrify(1) from ImageMagick.
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	${RUBY_PKGPREFIX}-subexec>=0.0.4:../../devel/ruby-subexec
DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=1.5.1:../../devel/hoe

pre-configure:
	${RM} -f ${WRKSRC}/.gitignore
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
