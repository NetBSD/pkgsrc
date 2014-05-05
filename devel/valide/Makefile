# $NetBSD: Makefile,v 1.31 2014/05/05 00:47:47 ryoon Exp $

DISTNAME=	valide-0.4.0
PKGREVISION=	24
CATEGORIES=	devel
MASTER_SITES=	http://valide.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.valaide.org/
COMMENT=	IDE for the Vala programming language

USE_TOOLS+=	pkg-config msgfmt intltool

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON+=	wscript waf \
			*/wscript_build \
			*/*/wscript_build
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.4.0

WAF_ENV=	PATH=${PATH} CC=${CC:Q} CXX=${CXX:Q} PREFIX=${PREFIX:Q} \
		CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
		LINKFLAGS=${LDFLAGS:Q} DESTDIR=${DESTDIR:Q}

.if defined(MAKE_JOBS)
WAF_ENV+=	JOBS=${MAKE_JOBS:Q}
.endif

do-configure:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf configure

do-build:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf

do-install:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf install

.include "../../lang/python/application.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
