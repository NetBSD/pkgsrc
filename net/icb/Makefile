# New ports collection makefile for:	icb client
# Version required:	5.0.5
# Date created:		18 March 1998
# Whom:			cjs
#
# $NetBSD: Makefile,v 1.3 1998/03/20 00:09:18 tv Exp $
#

DISTNAME=		icb-5.0.5
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/

MAINTAINER=		cjs@netbsd.org

do-configure:
	@cd ${WRKSRC}; \
	${SED} -e s,@PREFIX@,${PREFIX},g ${FILESDIR}/config >${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icb/icb ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/icbserverdb ${PREFIX}/libdata
	${INSTALL} -d ${PREFIX}/libdata/icb
	${INSTALL_SCRIPT} ${WRKSRC}/sample.icbrc \
		${WRKSRC}/contrib/bartender \
		${WRKSRC}/contrib/confuse \
		${WRKSRC}/contrib/echofile \
		${PREFIX}/libdata/icb

.include <bsd.port.mk>
