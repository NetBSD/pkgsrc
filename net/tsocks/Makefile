# $NetBSD: Makefile,v 1.11 2006/09/17 11:45:04 jmmv Exp $
#

DISTNAME=	tsocks-1.8beta5
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tsocks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tsocks.sourceforge.net/
COMMENT=	Transparent SOCKS proxying library

WRKSRC=		${WRKDIR}/tsocks-1.8
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-conf=${PKG_SYSCONFDIR}/tsocks.conf

EGDIR=			${PREFIX}/share/examples/tsocks

SUBST_CLASSES+=		tsocks
SUBST_STAGE.tsocks=	post-configure
SUBST_MESSAGE.tsocks=	Generating tsocks wrapper script.
SUBST_FILES.tsocks=	tsocks
SUBST_SED.tsocks=	-e "s|@SH@|${SH}|g" -e "s|@PREFIX@|${PREFIX}|g"

post-extract:
	${RM} -f ${WRKSRC}/config.cache
	${CP} ${FILESDIR}/tsocks.sh ${WRKSRC}/tsocks

post-configure: subst-tsocks

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tsocks ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/tsocks.conf.complex.example \
		${EGDIR}/tsocks.conf.complex
	${INSTALL_DATA} ${WRKSRC}/tsocks.conf.simple.example \
		${EGDIR}/tsocks.conf.simple

.include "../../mk/bsd.pkg.mk"
