# $NetBSD: Makefile,v 1.11 2003/12/24 09:53:48 jmmv Exp $
#

DISTNAME=		nethack_source_331_jtp_193
PKGNAME=		falcons-eye-1.9.3
PKGREVISION=		3
WRKSRC=			${WRKDIR}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=falconseye/}
EXTRACT_SUFX=		.zip

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://falconseye.sourceforge.net/
COMMENT=		Falcon's Eye NetHack

EXTRACT_CMD=		unzip -aq ${DOWNLOADED_DISTFILE}
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh

USE_BUILDLINK2=		yes
USE_X11=		yes

post-patch:
	@${MV} ${WRKSRC}/include/config.h ${WRKSRC}/config.h-pre
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g'                         \
		-e 's|@GZIP_PROGRAM@|'`${ECHO} ${GZIP_CMD} | ${AWK} '{ print $$1 }'`'|g' \
		< ${WRKSRC}/config.h-pre > ${WRKSRC}/include/config.h
	@${RM} -f ${WRKSRC}/config.h-pre
	@${SED} 's@XXXPREFIXXXX@${PREFIX}@g' \
		<${WRKSRC}/src/fe-config.in >${WRKSRC}/src/fe-config

pre-configure:
	@${CHMOD} 755 ${WRKSRC}/sys/unix/setup.sh

pre-install:
	@${CP} ${WRKSRC}/src/nethack ${WRKSRC}/src/falcons-eye

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/fe-config ${PREFIX}/bin

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
