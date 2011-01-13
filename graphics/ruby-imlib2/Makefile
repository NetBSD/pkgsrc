# $NetBSD: Makefile,v 1.22 2011/01/13 13:38:20 wiz Exp $

DISTNAME=	imlib2-ruby-0.5.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://pablotron.org/files/gems/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pablotron.org/software/imlib2-ruby/
COMMENT=	Imlib2 bindings for Ruby
LICENSE=	mit

GEM_CLEANBUILD=	Makefile *.o imlib2.${RUBY_DLEXT} mkmf.log

RUBY_REQD=		1.8.0

pre-configure:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../lang/ruby/gem.mk"

BUILDLINK_API_DEPENDS.imlib2+=      imlib2>=1.2.0nb2

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
