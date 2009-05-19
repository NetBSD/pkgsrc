# $NetBSD: Makefile,v 1.33 2009/05/19 08:59:26 wiz Exp $

DISTNAME=	gated-3-5-11
PKGNAME=	gated-3.5.11
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.zcu.cz/ftp/pub/security/merit/gated/ \
		http://www.funet.fi/pub/unix/tcpip/gated/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gated.org/
COMMENT=	Routing protocol daemon
LICENSE=	gated-license

RESTRICTED=		Required license from Merit
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

NOT_FOR_PLATFORM=	Interix-*-* # no userland routing table support

USE_TOOLS+=	pax

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
	${CHMOD} -w ${PREFIX}/bin/gdc ${PREFIX}/bin/ospf_monitor
	cd ${WRKSRC}/doc && pax -rw . ${PREFIX}/share/doc/gated
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/doc/gated
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/doc/gated
	${FIND} ${PREFIX}/share/doc/gated -type f -print | \
	${XARGS} ${CHMOD} -x

.include "../../mk/bsd.pkg.mk"
