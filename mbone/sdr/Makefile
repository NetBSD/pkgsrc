# $NetBSD: Makefile,v 1.30 2000/12/16 05:44:09 hubertf Exp $
#

DISTNAME=	sdr-2.7
PKGNAME=	sdr-2.7nb1
CATEGORIES=	mbone tk
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/2.7/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/

DEPENDS+=	tk-8.3.2:../../x11/tk

CRYPTO=		yes
USE_GMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/sys/inttypes.h)
EXTRA_FLAGS+=	-DHAVE_SYS_INTTYPES_H
MAKE_FLAGS+=	EXTRA_FLAGS="${EXTRA_FLAGS}"
.endif

.if ${OPSYS} == "SunOS"
SYSDIR= solaris
.else
SYSDIR= netbsd
.endif

do-configure:
	cd ${WRKSRC}/common	; ${SH} ./configure
.if ${OPSYS} == "SunOS"
	${CAT} ${WRKSRC}/sdr/solaris/Makefile.solaris ${WRKSRC}/sdr/src/Makefile.template > ${WRKSRC}/sdr/solaris/Makefile
.else
	${MKDIR} ${WRKSRC}/sdr/netbsd
	${CAT} ${FILESDIR}/Makefile.netbsd ${WRKSRC}/sdr/src/Makefile.template > ${WRKSRC}/sdr/netbsd/Makefile
.endif

do-build:
	cd ${WRKSRC}/common	; ${GMAKE}
	cd ${WRKSRC}/sdr/${SYSDIR}	; ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdr/${SYSDIR}/sdr ${PREFIX}/bin/sdr

.include "../../mk/bsd.pkg.mk"
