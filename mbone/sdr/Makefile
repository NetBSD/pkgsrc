# $NetBSD: Makefile,v 1.26 2000/08/18 22:46:42 hubertf Exp $
#

DISTNAME=	sdr-2.7
CATEGORIES=	mbone tk80
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/2.7/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/

DEPENDS+=	tk-8.0.5:../../x11/tk80

RESTRICTED=	"Uses encryption"
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

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
