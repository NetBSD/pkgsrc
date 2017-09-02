# $NetBSD: Makefile,v 1.6 2017/09/02 14:58:36 taca Exp $

DISTNAME=	sprockets-2.2.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sprockets/sprockets22/}
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sstephenson/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hike1>=1.2<2:../../devel/ruby-hike1
DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=1.4<2:../../www/ruby-rack14
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-tilt1>=1.1<2:../../textproc/ruby-tilt1

OVERRIDE_GEMSPEC=	:executables sprockets=sprockets22 \
			:files bin/sprockets=bin/sprockets22
RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${TEST} -f ${WRKSRC}/bin/sprockets22 || \
		${MV} ${WRKSRC}/bin/sprockets ${WRKSRC}/bin/sprockets22

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
