# $NetBSD: Makefile,v 1.38 2022/07/29 06:00:31 rin Exp $

DISTNAME=	imlib2-ruby-0.5.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	21
CATEGORIES=	graphics
MASTER_SITES=	http://pablotron.org/files/gems/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://pablotron.org/software/imlib2-ruby/
COMMENT=	Imlib2 bindings for Ruby
LICENSE=	mit

USE_TOOLS+=	pkg-config

GEM_CLEANBUILD=			Makefile *.o imlib2.${RUBY_DLEXT} mkmf.log .*.time
OVERRIDE_GEMSPEC=		:name=imlib2-ruby
BUILDLINK_API_DEPENDS.imlib2+=	imlib2>=1.9.1

pre-configure:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../lang/ruby/gem.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
