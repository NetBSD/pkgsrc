# $NetBSD: Makefile,v 1.34 2001/05/05 19:51:17 jlam Exp $
#

DISTNAME=	sdr-3.0
CATEGORIES=	mbone tk
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/3.0/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/
COMMENT=	MBone Session Directory

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	common-mml>=1.2.0:../common-mml

CRYPTO=		yes
USE_GMAKE=	yes

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

WRKSRC=		${WRKDIR}/sdr/${SYSDIR}
USE_GMAKE=	yes

do-configure:
	cd ${WRKSRC} ; ${SH} ./configure
.if ${OPSYS} == "SunOS"
	# Untested for sdr 3.0 !!!
	${CAT} ${WRKSRC}/sdr/solaris/Makefile.solaris ${WRKSRC}/sdr/src/Makefile.template > ${WRKSRC}/sdr/solaris/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdr ${PREFIX}/bin/sdr

.include "../../mk/bsd.pkg.mk"
