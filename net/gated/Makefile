# $NetBSD: Makefile,v 1.10 2001/10/25 20:16:53 agc Exp $
# FreeBSD Id: Makefile,v 1.17 1998/04/26 18:47:12 peter Exp 
#

DISTNAME=       gated-3-5-11
PKGNAME=        gated-3.5.11
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.gated.merit.edu/net-research/gated/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gated.org/
COMMENT=	Routing protocol daemon

RESTRICTED=		"Required license from Merit"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ALL_TARGET=	gated

post-extract:
	@${SED} -e 's#@PREFIX@#${PREFIX}#' <${FILESDIR}/configuration \
	    >${WRKSRC}/src/configs/netbsd
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/gated \
		> ${WRKDIR}/gated

do-configure:
	cd ${WRKSRC}/src; 						\
		obj=obj.`util/archtype`;				\
		${MKDIR} $$obj;						\
		${CP} configs/${LOWER_OPSYS} $$obj/Config;		\
		${RM} -f Config

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gated
	cd ${WRKSRC}/doc; ${PAX} -rwpe . ${PREFIX}/share/doc/gated
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/doc/gated
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/doc/gated
	${INSTALL_SCRIPT} ${WRKDIR}/gated ${PREFIX}/etc/rc.d

.include "../../mk/bsd.pkg.mk"
