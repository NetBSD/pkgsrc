# $NetBSD: Makefile,v 1.23 1999/10/27 17:14:09 agc Exp $
#

DISTNAME=	sdr-2.7
CATEGORIES=	mbone tk80
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/2.7/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/

BROKEN=		Bad patch sum file

DEPENDS+=	tk-8.0.5:../../x11/tk80

MIRROR_DISTFILE=	no
USE_GMAKE=	yes
USE_X11BASE=	yes

RESTRICTED=	"Uses encryption"

.if exists(/usr/include/sys/inttypes.h)
EXTRA_FLAGS+=	-DHAVE_SYS_INTTYPES_H
MAKE_FLAGS+=	EXTRA_FLAGS="${EXTRA_FLAGS}"
.endif

do-configure:
	cd ${WRKSRC}/common	; ${SH} ./configure
	${MKDIR} ${WRKSRC}/sdr/netbsd
	${CAT} ${FILESDIR}/Makefile.netbsd ${WRKSRC}/sdr/src/Makefile.template > ${WRKSRC}/sdr/netbsd/Makefile

do-build:
	cd ${WRKSRC}/common	; ${GMAKE}
	cd ${WRKSRC}/sdr/netbsd	; ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdr/netbsd/sdr ${PREFIX}/bin/sdr

.include "../../mk/bsd.pkg.mk"
