# $NetBSD: Makefile,v 1.19 2005/03/24 21:12:58 wiz Exp $

DISTNAME=       gated-3-5-11
PKGNAME=        gated-3.5.11
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.rge.com/pub/networking/gated/ \
		http://www.zcu.cz/ftp/pub/security/merit/gated/ \
		http://www.funet.fi/pub/unix/tcpip/gated/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gated.org/
COMMENT=	Routing protocol daemon

RESTRICTED=		"Required license from Merit"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
RCD_SCRIPTS=		gated
RCD_SCRIPT_SRC.gated=	${FILESDIR}/gated

BUILD_TARGET=	gated

post-extract:
	@${SED} -e 's#@PREFIX@#${PREFIX}#' <${FILESDIR}/configuration \
	    >${WRKSRC}/src/configs/netbsd

do-configure:
	cd ${WRKSRC}/src; 						\
		obj=obj.`util/archtype`;				\
		${MKDIR} $$obj;						\
		${CP} configs/${LOWER_OPSYS} $$obj/Config;		\
		${RM} -f Config

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gated
	cd ${WRKSRC}/doc && ${PAX} -rw -pe . ${PREFIX}/share/doc/gated
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/doc/gated
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/doc/gated

.include "../../mk/bsd.pkg.mk"
