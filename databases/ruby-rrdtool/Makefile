# $NetBSD: Makefile,v 1.56 2026/09/02 19:01:19 wiz Exp $

PKGREVISION= 1
.include "../../databases/rrdtool/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}

USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${DISTNAME}/bindings/ruby ${DISTNAME}/src
WRKSRC=			${WRKDIR}/${DISTNAME}/bindings/ruby
MAKE_ENV+=		ABS_TOP_BUILDDIR=${WRKDIR}/${DISTNAME}

USE_TOOLS+=		pkg-config

#pre-configure:
#	${RM} ${WRKDIR}/${DISTNAME}/src/rrd_config.h

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
