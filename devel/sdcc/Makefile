# $NetBSD: Makefile,v 1.9 2001/05/12 06:36:42 tron Exp $
# FreeBSD: ports/devel/sdcc/Makefile,v 1.5 2000/04/15 15:13:38 knu Exp

DISTNAME=	sdcc-2.2.1-src
PKGNAME=	sdcc-2.2.1
CATEGORIES=	devel lang
MASTER_SITES=	http://web.kd0yu.com/sdcc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sdcc.sourceforge.net/
COMMENT=	Cross compile 8051 code

ALL_TARGET=	dep all
WRKSRC=		${WRKDIR}/${PKGNAME}

#
# This HACK circumvent a problem with the use of
# yacc that breaks the building process of sdcc.
# Use of bison fixes this problem for now.
#
BUILD_DEPENDS+=	bison-*:../../devel/bison
# we link to the static boehm-gc library so we only
# need this at compile time
BUILD_DEPENDS+=	boehm-gc-*:../../devel/boehm-gc
YACC=		bison

GNU_CONFIGURE=	yes
USE_GMAKE=      yes
USE_PERL5=	yes
CONFIGURE_ARGS+=--datadir=${LOCALBASE}/share/sdcc

# needed for some arch's.  -fdollars-in-identifiers is enabled
# by default on some, not on others
CPPFLAGS+=	-fdollars-in-identifiers
CONFIGURE_ENV+= MACHINE_ARCH=${MACHINE_ARCH}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=	-I${WRKDIR}/include -DYY_NEVER_INTERACTIVE

post-extract:
	${MKDIR} ${WRKDIR}/include
	${LN} -fs /usr/include/sys/endian.h ${WRKDIR}/include
	${RM} -f ${WRKSRC}/as/mcs51/string.h ${WRKSRC}/as/z80/string.h
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sdcc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sdcc/avr
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sdcc/z80
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/sdcc/
	${INSTALL_DATA} ${WRKSRC}/doc/*.sgml ${PREFIX}/share/doc/sdcc/
	${INSTALL_DATA} ${WRKSRC}/doc/*.lyx ${PREFIX}/share/doc/sdcc/
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${PREFIX}/share/doc/sdcc/
	${INSTALL_DATA} ${WRKSRC}/doc/avr/avr_design.txt ${PREFIX}/share/doc/sdcc/avr
	${INSTALL_DATA} ${WRKSRC}/doc/z80/README ${PREFIX}/share/doc/sdcc/z80

.include "../../mk/bsd.pkg.mk"
