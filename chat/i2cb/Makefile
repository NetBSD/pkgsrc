# $NetBSD: Makefile,v 1.14 2005/02/22 22:18:20 jwise Exp $
#

DISTNAME=	i2cb-6.0_ALPHA
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.draga.com/~jwise/i2cb/
COMMENT=	Next generation Internet Citicen's Band chat client

WRKSRC=		${WRKDIR}/icb
USE_BUILDLINK3=		yes
USE_GNU_READLINE=	yes

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

.include "../../lang/tcl83/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
