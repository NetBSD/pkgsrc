# $NetBSD: Makefile,v 1.28 2007/04/24 12:06:18 tron Exp $

DISTNAME=	gated-3-5-11
PKGNAME=	gated-3.5.11
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://ftp.rge.com/pub/networking/gated/ \
		http://www.zcu.cz/ftp/pub/security/merit/gated/ \
		http://www.funet.fi/pub/unix/tcpip/gated/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gated.org/
COMMENT=	Routing protocol daemon

NOT_FOR_PLATFORM=	Interix-*-* # no userland routing table support

RESTRICTED=		Required license from Merit
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

RCD_SCRIPTS=		gated
RCD_SCRIPT_SRC.gated=	${FILESDIR}/gated

BUILD_TARGET=	gated

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 sbin share/doc/gated

post-extract:
	@${SED} -e 's#@PREFIX@#${PREFIX}#' <${FILESDIR}/configuration \
	    >${WRKSRC}/src/configs/netbsd
	@${SED} -e 's#@PREFIX@#${PREFIX}#' <${FILESDIR}/configuration \
	    >${WRKSRC}/src/configs/dragonfly

do-configure:
	cd ${WRKSRC}/src; 						\
		obj=obj.`util/archtype`;				\
		${MKDIR} $$obj;						\
		${CP} configs/${LOWER_OPSYS} $$obj/Config;		\
		${RM} -f Config

post-install:
	cd ${WRKSRC}/doc && ${PAX} -rw -pe . ${PREFIX}/share/doc/gated
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/doc/gated
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/doc/gated

.include "../../mk/bsd.pkg.mk"
