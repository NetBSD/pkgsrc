# $NetBSD: Makefile,v 1.8 1998/08/20 15:17:27 tsarna Exp $
# FreeBSD Id: Makefile,v 1.19 1998/03/08 06:44:48 obrien Exp
#

DISTNAME=		lsof_4.36_W
PKGNAME=		lsof-4.36
CATEGORIES=		sysutils
MASTER_SITES=		ftp://vic.cc.purdue.edu/pub/tools/unix/lsof/  \
			ftp://ftp.cert.dfn.de/pub/tools/admin/lsof/  \
			ftp://ftp.auscert.org.au/pub/mirrors/vic.cc.purdue.edu/lsof/  \
			ftp://ftp.web.ad.jp/pub/UNIX/tools/lsof/  \
			ftp://ftp.sunet.se/pub/unix/admin/lsof/

PATCH_SITES=		ftp://vic.cc.purdue.edu/pub/tools/unix/lsof/patches/4.36/
PATCHFILES=		fd_lookup_patch

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www-rcd.cc.purdue.edu/abe/

CONFLICTS=		lsof-4.29 lsof-4.31 lsof-4.33

WRKSRC=			${WRKDIR}/${SRCBALL_NAME}
DIST_SUBDIR=		lsof

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
OPSYS!=			uname -s
.if (${OPSYS} == "FreeBSD")
CONFIGURE_ARGS=		-n freebsd
.elif (${OPSYS} == "NetBSD")
CONFIGURE_ARGS=		-n netbsd
.endif

SRCBALL_NAME=		${DISTNAME:S/_W$//}

post-extract:
	@( cd ${WRKDIR} ; \
	EXPMD5=`${GREP} MD5 README.${SRCBALL_NAME} | ${SED} 's/^[ ]*//'` ; \
	CALCMD5=`${MD5} ${SRCBALL_NAME}.tar` ; \
	if [ "$${EXPMD5}"X != "$${CALCMD5}"X ]; then \
		${ECHO} "Expected and calculated MD5 signatures don't agree." ; \
		${ECHO} "($$EXPMD5 != $$CALCMD5)" ; \
		${FALSE} ; \
	fi ; \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS:S/z//} ${SRCBALL_NAME}.tar \
	)
	@( cd ${WRKSRC} ; ${ECHO} "y" | ./Inventory || exit 1 )

do-install:
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m 2755 -g kmem \
		${WRKSRC}/lsof ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lsof.man ${PREFIX}/man/man1/lsof.1
	@${MKDIR} ${PREFIX}/share/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/share/lsof
	@chmod 0444 ${PREFIX}/share/lsof/00*

.include "../../mk/bsd.pkg.mk"
