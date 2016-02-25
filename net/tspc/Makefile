# $NetBSD: Makefile,v 1.23 2016/02/25 16:20:53 jperkin Exp $

DISTNAME=		tspc-2.1.1-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.hexago.com/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Tunnel Setup Protocol Client for Freenet6
HOMEPAGE=		http://www.hexago.com/

BROKEN_EXCEPT_ON_PLATFORM=	NetBSD-*-* OpenBSD-*-* FreeBSD-*-* Linux-*-* \
				Darwin-*-* SunOS-*-*

AUTO_MKDIRS=		yes

OPSYSVARS+=		TARGET
TARGET.SunOS=		solaris
TARGET.*=		${LOWER_OPSYS}

MAKE_ENV+=		target=${TARGET:Q}
MAKE_ENV+=		configdir=${PREFIX}/share/tspc

WRKSRC=			${WRKDIR}/tspc2

CONF_FILES+=		${PREFIX}/share/examples/tspc/tspc.conf ${PKG_SYSCONFDIR}/tspc.conf
CONF_FILES_MODE=	0600

RCD_SCRIPTS=		tspc

PLIST_SUBST+=		TARGET=${TARGET:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tspc ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/man5/tspc.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN} ${WRKSRC}/man/man8/tspc.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${WRKSRC}/bin/tspc.conf.sample ${DESTDIR}${PREFIX}/share/examples/tspc/tspc.conf
	${INSTALL_SCRIPT} ${WRKSRC}/template/${TARGET}.sh ${DESTDIR}${PREFIX}/share/tspc/template/
	${INSTALL_SCRIPT} ${WRKSRC}/template/checktunnel.sh ${DESTDIR}${PREFIX}/share/tspc/template/
	${INSTALL_DATA} ${WRKSRC}/template/README ${DESTDIR}${PREFIX}/share/tspc/template/
	${INSTALL_DATA} ${WRKSRC}/template/variables_environ ${DESTDIR}${PREFIX}/share/tspc/template/

.include "../../mk/bsd.pkg.mk"
