# $NetBSD: Makefile,v 1.17 2002/09/18 21:16:24 tron Exp $

DISTNAME=	nntpclnt-1.6.1
PKGREVISION=	3
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/nntp/

MAINTAINER=	packages@netbsd.org
COMMENT=	NNTP client library and inews client posting program

CONFLICTS+=	inn-[0-9]*

LICENSE=	nntpclnt-license
RESTRICTED=	"Do not sell, rent, trade, market, or use for monetary profit"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

ALL_TARGET=	inews
PKG_GROUPS=	news

.include "../../mk/bsd.prefs.mk"

CONFIG_SH=	${FILESDIR}/config.${OPSYS}.sh

do-configure:
	${SED} -e s,@PREFIX@,${PREFIX}, ${CONFIG_SH} >${WRKSRC}/config.sh
	@cd ${WRKSRC} && ${SH} Makefile.SH && ${SH} config.h.SH

post-build:
	cd ${WRKSRC} && \
		${AR} clq libnntpclnt.a nntpclnt.o && ${RANLIB} libnntpclnt.a

do-install:
	${INSTALL_PROGRAM} -g ${PKG_GROUPS} -m 2555 ${WRKSRC}/inews \
	  ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/nntp.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libnntpclnt.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/nntpclnt.3 ${PREFIX}/man/man3/
	${INSTALL_DATA_DIR} ${PREFIX}/etc/nntp

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"

