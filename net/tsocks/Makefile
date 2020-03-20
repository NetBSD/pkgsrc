# $NetBSD: Makefile,v 1.21 2020/03/20 11:58:11 nia Exp $
#

DISTNAME=	tsocks-1.8beta5
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tsocks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tsocks.sourceforge.net/
COMMENT=	Transparent SOCKS proxying library
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/tsocks-1.8
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-conf=${PKG_SYSCONFDIR}/tsocks.conf

EGDIR=			${PREFIX}/share/examples/tsocks

SUBST_CLASSES+=		tsocks
SUBST_STAGE.tsocks=	post-configure
SUBST_MESSAGE.tsocks=	Generating tsocks wrapper script.
SUBST_FILES.tsocks=	tsocks
SUBST_VARS.tsocks=	SH
SUBST_VARS.tsocks+=	PREFIX

INSTALLATION_DIRS+=	${EGDIR}

post-extract:
	${RM} -f ${WRKSRC}/config.cache
	${CP} ${FILESDIR}/tsocks.sh ${WRKSRC}/tsocks

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tsocks ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tsocks.conf.complex.example \
		${DESTDIR}${EGDIR}/tsocks.conf.complex
	${INSTALL_DATA} ${WRKSRC}/tsocks.conf.simple.example \
		${DESTDIR}${EGDIR}/tsocks.conf.simple

.include "../../mk/bsd.pkg.mk"
