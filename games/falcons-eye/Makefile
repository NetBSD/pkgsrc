# $NetBSD: Makefile,v 1.1.1.1 2002/01/21 11:56:16 pooka Exp $
#

DISTNAME=		nethack_source_331_jtp_193
PKGNAME=		falcons-eye-1.9.3
WRKSRC=			${WRKDIR}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=falconseye/}
EXTRACT_SUFX=		.zip

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://falconseye.sourceforge.net/
COMMENT=		Falcon's Eye NetHack

EXTRACT_CMD=		unzip -aq ${DOWNLOADED_DISTFILE}
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh

BUILDLINK_ONLY=		yes

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

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
