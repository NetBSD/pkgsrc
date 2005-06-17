# $NetBSD: Makefile,v 1.24 2005/06/17 03:50:29 jlam Exp $

DISTNAME=	nntpclnt-1.6.1
PKGREVISION=	5
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/nntp/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	NNTP client library and inews client posting program

CONFLICTS+=	inn-[0-9]*

LICENSE=	nntpclnt-license
RESTRICTED=	"Do not sell, rent, trade, market, or use for monetary profit"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

BUILD_TARGET=	inews
PKG_GROUPS=	news
USE_PKGINSTALL=	yes
PKG_SYSCONFSUBDIR=	nntp

PLIST_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

CONFIG_SH=	${FILESDIR}/config.${OPSYS}.sh
ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-*

INSTALLATION_DIRS=	bin include lib man/man3

do-configure:
	${SED} -e s,@PREFIX@,${PREFIX}, -e s,@PKGSYSCONFDIR@,${PKG_SYSCONFDIR}, \
		${CONFIG_SH} >${WRKSRC}/config.sh
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
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
