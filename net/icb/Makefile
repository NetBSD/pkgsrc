# New ports collection makefile for:	icb client
# Version required:	
# Date created:		18 March 1998
# Whom:			cjs
#
# $NetBSD: Makefile,v 1.1 1998/03/18 22:40:47 cjs Exp $
#

DISTNAME=		icb-5.0.5
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/

MAINTAINER=		cjs@netbsd.org

do-install:
	pwd
	${INSTALL_PROGRAM} ${WRKSRC}/icb/icb ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/icbserverdb ${PREFIX}/libdata
	install -d ${PREFIX}/libdata/icb
	${INSTALL_PROGRAM} ${WRKSRC}/sample.icbrc \
		${WRKSRC}/contrib/bartender \
		${WRKSRC}/contrib/confuse \
		${WRKSRC}/contrib/echofile \
		${PREFIX}/libdata/icb

.include <bsd.port.mk>
