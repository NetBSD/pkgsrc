# $NetBSD: Makefile,v 1.36 2015/07/12 07:22:08 dholland Exp $
#

DISTNAME=	tripwire-1.2
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cerias.purdue.edu/about/history/coast/coast-library.html
COMMENT=	File and directory integrity checker

USE_TOOLS+=	pax lex yacc
MAKE_JOBS_SAFE=	NO

BROKEN_EXCEPT_ON_PLATFORM=	NetBSD-*-* FreeBSD-*-* SunOS-*-*

PKG_SYSCONFSUBDIR=	tripwire
OWN_DIRS=		${PKG_SYSCONFDIR}/databases
EGDIR=			${PREFIX}/share/examples/tripwire
CONF_FILES=		${EGDIR}/tripwire.conf ${PKG_SYSCONFDIR}/tripwire.conf
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

AUTO_MKDIRS=			yes

post-extract:
	cd ${WRKDIR} && pax -O -rf T1.2.tar
	${CP} ${FILESDIR}/conf-${LOWER_OPSYS}.h ${WRKSRC}/configs

pre-configure:
	${MV} ${WRKSRC}/include/config.h ${WRKSRC}/include/config.h.in
	${SED} -e 's|@localbase@|${LOCALBASE}|g'			\
		-e 's|@LOWER_OPSYS@|${LOWER_OPSYS}|g'			\
		-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'		\
		${WRKSRC}/include/config.h.in > ${WRKSRC}/include/config.h

PRE_ROOT_CMD=	${CHMOD} -R go+rwx ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/designdoc.ps ${DESTDIR}${PREFIX}/share/doc/tripwire
	${SED} -e 's|@localbase@|${LOCALBASE}|g' -e 's|@x11base@|${X11BASE}|g' \
		${FILESDIR}/tw.conf.${LOWER_OPSYS} > ${DESTDIR}${EGDIR}/tripwire.conf

.include "../../mk/bsd.pkg.mk"
