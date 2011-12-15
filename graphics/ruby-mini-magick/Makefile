# $NetBSD: Makefile,v 1.8 2011/12/15 15:38:05 taca Exp $

DISTNAME=	mini_magick-3.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/mini-magick/
COMMENT=	Ruby wrapper for ImageMagick command line
LICENSE=	mit

# MiniMagick uses identify(1) and mogrify(1) from ImageMagick.
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	${RUBY_PKGPREFIX}-subexec>=0.1.0<0.3:../../devel/ruby-subexec

OVERRIDE_GEMSPEC+= subexec>=0.1

pre-configure:
	${RM} -f ${WRKSRC}/.gitignore
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
