# $NetBSD: Makefile,v 1.12 2001/11/28 04:49:01 jlam Exp $
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
# XXX - This HACK circumvent a problem with the use of yacc that breaks the
# XXX - building process of sdcc.  Use of bison fixes this problem for now.
#
BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
YACC=		bison

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=      	YES
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/sdcc

# needed for some arch's.  -fdollars-in-identifiers is enabled
# by default on some, not on others
CPPFLAGS+=		-fdollars-in-identifiers
CONFIGURE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=		-DYY_NEVER_INTERACTIVE

post-extract:
	${RM} -f ${WRKSRC}/as/mcs51/string.h ${WRKSRC}/as/z80/string.h

pre-configure: sys-endian-buildlink

sys-endian-buildlink:
	${MKDIR} ${BUILDLINK_DIR}/include
	${LN} -fs /usr/include/sys/endian.h ${BUILDLINK_DIR}/include
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

.include "../../devel/boehm-gc/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
