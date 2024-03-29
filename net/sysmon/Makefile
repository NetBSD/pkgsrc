# $NetBSD: Makefile,v 1.13 2023/10/24 22:10:34 wiz Exp $

DISTNAME=		sysmon-0.93
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		ftp://puck.nether.net/pub/jared/

MAINTAINER=		pettai@NetBSD.org
#HOMEPAGE=		http://www.sysmon.org/
COMMENT=		Small and fast network monitoring tool
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

BUILD_DEFS+=		IPV6_READY

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/sysmon
SMDOC=			${PREFIX}/share/doc/sysmon

CONF_FILES=		${EGDIR}/sysmon.conf.dist \
			${PKG_SYSCONFDIR}/sysmon.conf

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/autoconf/Makefile.in
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths=	-e 's,@destdir@,${DESTDIR},g'

INSTALLATION_DIRS=	share/examples/sysmon
INSTALLATION_DIRS+=	share/doc/sysmon bin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/sysmon.conf.dist ${DESTDIR}${EGDIR}/sysmon.conf.dist
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DESTDIR}${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES ${DESTDIR}${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DESTDIR}${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/*.jpg  ${DESTDIR}${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt  ${DESTDIR}${SMDOC}
	${INSTALL_DATA} ${WRKSRC}/docs/sysmon.conf.man \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/sysmon.conf.5
	${INSTALL_DATA} ${WRKSRC}/docs/sysmon.man \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/sysmon.8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
