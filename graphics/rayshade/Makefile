# $NetBSD: Makefile,v 1.2 1998/09/15 17:05:04 agc Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/05/26 04:04:11 mph Exp
#

DISTNAME=	rayshade.4.0
PKGNAME=	rayshade-4.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://graphics.stanford.edu/pub/rayshade/	\
		ftp://ftp.princeton.edu/pub/Graphics/rayshade.4.0/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     packages@netbsd.org

.include "../../mk/bsd.prefs.mk"

.ifdef WRKOBJDIR
BUILD_ROOT=	${WRKOBJDIR}
.else
BUILD_ROOT=	${PKGSRCDIR}
.endif

BUILD_DEPENDS=	${BUILD_ROOT}/graphics/urt/${WRKDIR:T}/include/rle.h:../../graphics/urt:configure
DEPENDS+=	urt-3.1b1:../../graphics/urt

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS+=	< ${WRKDIR}/config.ans
ALL_TARGET=

pre-configure:
	${SED} -e 's|@CFLAGS@|${CFLAGS}|g' 			\
		-e 's|\$${PREFIX}|${PREFIX}|g'			\
		-e 's|\$${URTDIR}|${BUILD_ROOT}/graphics/urt/${WRKDIR:T}|g' \
		${FILESDIR}/config.ans > ${WRKDIR}/config.ans

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/rayshade/rayshade $(PREFIX)/bin
	$(INSTALL_DATA) $(WRKSRC)/libray/libray.a $(PREFIX)/lib
	${RANLIB} ${PREFIX}/lib/libray.a
	$(INSTALL_DATA) $(WRKSRC)/libshade/libshade.a $(PREFIX)/lib
	${RANLIB} ${PREFIX}/lib/libshade.a
	$(MKDIR) $(PREFIX)/share/doc/rayshade
	$(INSTALL_DATA) $(WRKSRC)/Doc/Guide/* $(PREFIX)/share/doc/rayshade
	$(INSTALL_DATA) $(WRKSRC)/Doc/quickref.txt $(PREFIX)/share/doc/rayshade
	$(MKDIR) $(PREFIX)/share/examples/rayshade
	$(INSTALL_DATA) $(WRKSRC)/Examples/* $(PREFIX)/share/examples/rayshade

.include "../../mk/bsd.pkg.mk"
