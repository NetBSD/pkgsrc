# $NetBSD: Makefile,v 1.20 2016/04/23 06:23:49 adam Exp $

DISTNAME=	rrdtool-1.6.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases graphics net
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oss.oetiker.ch/rrdtool/
COMMENT=	Ruby binding for rrdtool
LICENSE=	gnu-gpl-v2

USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${DISTNAME}/bindings/ruby ${DISTNAME}/src
WRKSRC=			${WRKDIR}/${DISTNAME}/bindings/ruby
MAKE_ENV+=		ABS_TOP_BUILDDIR=${WRKDIR}/${DISTNAME}

pre-configure:
	rm ${WRKDIR}/${DISTNAME}/src/rrd_config.h

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
