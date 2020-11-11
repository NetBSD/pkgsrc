# $NetBSD: Makefile,v 1.22 2020/11/11 16:22:54 jperkin Exp $

DISTNAME=	tsocks-1.8beta5
PKGREVISION=	4
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

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		tsocks
SUBST_STAGE.tsocks=	post-configure
SUBST_MESSAGE.tsocks=	Generating tsocks wrapper script.
SUBST_FILES.tsocks=	tsocks
SUBST_VARS.tsocks=	PREFIX SH
.if ${OPSYS} == "Darwin"
SUBST_SED.tsocks=	-e 's,@PRELOAD_VAR@,DYLD_INSERT_LIBRARIES,g'
SUBST_SED.tsocks+=	-e 's,@SOEXT@,dylib,g'
.else
SUBST_SED.tsocks=	-e 's,@PRELOAD_VAR@,LD_PRELOAD,g'
SUBST_SED.tsocks+=	-e 's,@SOEXT@,so,g'
.endif

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
