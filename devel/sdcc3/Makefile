# $NetBSD: Makefile,v 1.37 2020/03/20 11:57:33 nia Exp $

DISTNAME=	sdcc-src-3.9.0
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sdcc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://sdcc.sourceforge.net/
COMMENT=	Cross compile microcontroller code
LICENSE=	gnu-gpl-v2

DEPENDS+=	gputils-[0-9]*:../../devel/gputils

USE_LANGUAGES=	c c++

# XXX - This HACK circumvent a problem with the use of yacc that breaks the
# XXX - building process of sdcc.  Use of bison fixes this problem for now.
#
USE_TOOLS+=	bison makeinfo
INFO_FILES=	yes

#BUILD_TARGET=	dep all

WRKSRC=			${WRKDIR}/sdcc-${PKGVERSION_NOREV}
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake lex:run perl:run

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/sdcc
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/sdcc

# needed for some arch's.  -fdollars-in-identifiers is enabled
# by default on some, not on others
CPPFLAGS+=		-fdollars-in-identifiers
CONFIGURE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}
CONFIGURE_ENV+=		sdcc_cv_c_ggdb="no"

REPLACE_PYTHON=		support/scripts/as2gbmap.py
MAKE_JOBS_SAFE=		NO

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=		-DYY_NEVER_INTERACTIVE

pre-configure: sys-endian-buildlink

sys-endian-buildlink:
	${MKDIR} ${BUILDLINK_DIR}/include
	${LN} -fs /usr/include/sys/endian.h ${BUILDLINK_DIR}/include
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.lyx ${DESTDIR}${PREFIX}/share/doc/sdcc
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/sdcc

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
