# $NetBSD: Makefile,v 1.7 2000/08/18 22:46:44 hubertf Exp $
# FreeBSD Id: Makefile,v 1.17 1998/04/26 18:47:12 peter Exp 
#

DISTNAME=       gated-3-5-11
PKGNAME=        gated-3.5.11
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.gated.merit.edu/net-research/gated/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gated.org/

RESTRICTED=		"Required license from Merit"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ALL_TARGET=	gated

post-extract:
	@${SED} -e 's#@PREFIX@#${PREFIX}#' <${FILESDIR}/configuration \
	    >${WRKSRC}/src/configs/netbsd

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gated
	cd ${WRKSRC}/doc ; \
	${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/gated ; ${GTAR} pvxf - )
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/doc/gated
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/doc/gated

.include "../../mk/bsd.pkg.mk"
