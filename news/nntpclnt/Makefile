# New ports collection Makefile for: nntpclnt
# Version required:	1.6.1
#
# Date created:         25 March 1998
# Whom:                 tv@netbsd.org
#
# $NetBSD: Makefile,v 1.3 1998/03/28 19:48:28 cjs Exp $
#

DISTNAME=	nntpclnt-1.6.1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/nntp/

MAINTAINER=	tv@netbsd.org

ALL_TARGET=	inews

MAN3=	nntpclnt.3

do-configure:
	${SED} -e s,@PREFIX@,${PREFIX}, ${FILESDIR}/config.sh >${WRKSRC}/config.sh
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
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
