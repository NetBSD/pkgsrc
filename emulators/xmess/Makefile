# $NetBSD: Makefile,v 1.1 1998/07/09 12:34:56 mycroft Exp $
#

DISTNAME=		unix01
PKGNAME=		xmess-0.1
CATEGORIES=		emulators games x11
MASTER_SITES=		http://internetter.com/titan/mess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		mycroft@NetBSD.ORG

RUN_DEPENDS=		unzip:../../archivers/unzip
DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11=		yes
USE_GMAKE=		yes
MAKE_ENV+=		OPSYS=${OPSYS} ARCH=${ARCH} DESTDIR=${DESTDIR} \
			INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}"

WRKSRC=			${WRKDIR}/xmess-0.1

MESSDIR=		${PREFIX}/share/mess

post-patch:
	${CP} ${WRKSRC}/makefile.unix ${WRKSRC}/Makefile
	${SED} 's|@MESSDIR@|${MESSDIR}|' ${WRKSRC}/doc/xmessrc.dist >${WRKSRC}/doc/xmessrc
	${MV} ${WRKSRC}/src/unix/netbsd_i386.c ${WRKSRC}/src/unix/netbsd.c

post-install:
	${MKDIR} -p ${MESSDIR}
	${CP} ${WRKSRC}/doc/xmessrc ${MESSDIR}/xmessrc
	@${ECHO} Remember to set MESSDIR to ${MESSDIR}.

.include "../../mk/bsd.pkg.mk"
