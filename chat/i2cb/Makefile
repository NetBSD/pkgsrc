# $NetBSD: Makefile,v 1.1.1.1 2002/11/14 00:55:44 hubertf Exp $
#

DISTNAME=	icb
PKGNAME=	i2cb-6.0_ALPHA
CATEGORIES=	chat
MASTER_SITES=	http://www.draga.com/~jwise/i2cb/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.draga.com/~jwise/i2cb/
COMMENT=	Next generation Internet Citicen's Band chat client

WRKSRC=		${WRKDIR}/icb

USE_BUILDLINK_ONLY=	# defined

post-extract:
		${RM} -f ${WRKSRC}/src/.depend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/icb ${PREFIX}/bin/i2cb
	${INSTALL_SCRIPT} ${WRKSRC}/icbserverdb ${PREFIX}/libdata/i2cbserverdb
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/i2cb
	${INSTALL_SCRIPT} ${WRKSRC}/sample.icbrc \
		${PREFIX}/libdata/i2cb/sample.i2cbrc
	${INSTALL_SCRIPT} \
		${WRKSRC}/contrib/bartender \
		${WRKSRC}/contrib/confuse \
		${WRKSRC}/contrib/echofile \
		${PREFIX}/libdata/i2cb

.include "../../mk/bsd.pkg.mk"
