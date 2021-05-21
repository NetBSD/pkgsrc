# $NetBSD: Makefile,v 1.14 2021/05/21 16:47:03 nia Exp $

DISTNAME=	rubigen-1.5.5
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drnic.github.com/rubigen
COMMENT=	Ruby stub generator
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

RUBY_RAILS_ACCEPTED=	# defined

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	    ${MV} install_rubigen_scripts install_rubigen_scripts${RUBY_SUFFIX}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} rubigen rubigen${RUBY_SUFFIX}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ruby_app ruby_app${RUBY_SUFFIX}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
