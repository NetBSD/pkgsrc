# $NetBSD: Makefile,v 1.41 2004/06/08 12:23:59 cjep Exp $
#

DISTNAME=	sdr-3.0
CATEGORIES=	mbone tk
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/3.0/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/
COMMENT=	MBone Session Directory

DEPENDS+=	tk>=8.3.2:../../x11/tk83
DEPENDS+=	common-mml>=1.2.0:../common-mml

WRKSRC=		${WRKDIR}/sdr/${SYSDIR}
CRYPTO=		yes
USE_GNU_TOOLS+=	make

BUILD_DEFS+=		USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+= --enable-ipv6
.endif

.if exists(/usr/include/sys/inttypes.h)
EXTRA_FLAGS+=	-DHAVE_SYS_INTTYPES_H
MAKE_FLAGS+=	EXTRA_FLAGS="${EXTRA_FLAGS}"
.endif

.if ${OPSYS} == "SunOS"
SYSDIR= solaris
.else
SYSDIR= freebsd
.endif

post-patch:
	${MV} ${WRKSRC}/../src/sdr.tcl ${WRKSRC}/../src/sdr.tcl.in &&	\
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/../src/sdr.tcl.in >	\
		${WRKSRC}/../src/sdr.tcl

do-configure:
	cd ${WRKSRC} ; ${SH} ./configure
.if ${OPSYS} == "SunOS"
	# Untested for sdr 3.0 !!!
	${CAT} ${WRKSRC}/sdr/solaris/Makefile.solaris ${WRKSRC}/sdr/src/Makefile.template > ${WRKSRC}/sdr/solaris/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdr ${PREFIX}/bin/sdr

.include "../../mk/bsd.pkg.mk"
