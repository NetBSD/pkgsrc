# $NetBSD: Makefile,v 1.39 2013/12/08 03:55:43 dholland Exp $

DISTNAME=	gated-3-5-11
PKGNAME=	gated-3.5.11
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.funet.fi/pub/unix/tcpip/gated/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gated.org/
COMMENT=	Routing protocol daemon
LICENSE=	gated-license

SPECIAL_PERMS+=		bin/gdc ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 4510 \
			bin/ospf_monitor ${SETUID_ROOT_PERMS}

RESTRICTED=		Required license from Merit
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

NOT_FOR_PLATFORM=	Interix-*-* # no userland routing table support

USE_TOOLS+=	lex yacc pax

RCD_SCRIPTS=		gated
RCD_SCRIPT_SRC.gated=	${FILESDIR}/gated

BUILD_TARGET=	gated

INSTALL_MAKE_FLAGS=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
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
	cd ${WRKSRC}/doc && pax -rw . ${DESTDIR}${PREFIX}/share/doc/gated
	${CHOWN} -R ${SHAREOWN} ${DESTDIR}${PREFIX}/share/doc/gated
	${CHGRP} -R ${SHAREGRP} ${DESTDIR}${PREFIX}/share/doc/gated
	${FIND} ${DESTDIR}${PREFIX}/share/doc/gated -type f -print | \
	${XARGS} ${CHMOD} -x

.include "../../mk/bsd.pkg.mk"
