# $NetBSD: Makefile,v 1.8 1999/09/20 19:21:21 kim Exp $
#

DISTNAME=	nntpclnt-1.6.1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/nntp/

MAINTAINER=	tv@netbsd.org

CONFLICTS+=	inn-*

ALL_TARGET=	inews

.include "../../mk/bsd.prefs.mk"

CONFIG_SH=	${FILESDIR}/config.${OPSYS}.sh

do-configure:
	${SED} -e s,@PREFIX@,${PREFIX}, ${CONFIG_SH} >${WRKSRC}/config.sh
	@cd ${WRKSRC} && sh Makefile.SH && sh config.h.SH

post-build:
	cd ${WRKSRC} && \
		${AR} clq libnntpclnt.a nntpclnt.o && ${RANLIB} libnntpclnt.a

do-install:
	${INSTALL_PROGRAM} -g news -m 2555 ${WRKSRC}/inews ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/nntp.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libnntpclnt.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/nntpclnt.3 ${PREFIX}/man/man3/
	${INSTALL_DATA_DIR} ${PREFIX}/etc/nntp

.include "../../mk/bsd.pkg.mk"
