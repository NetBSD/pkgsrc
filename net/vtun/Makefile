# $NetBSD: Makefile,v 1.57 2020/03/20 11:58:12 nia Exp $

DISTNAME=	vtun-3.0.3
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vtun/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vtun.sourceforge.net/
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ssl-headers=${SSLBASE}/include/openssl
CONFIGURE_ARGS+=	--with-ssl-lib=${SSLBASE}/lib
CONFIGURE_ARGS+=	--with-lzo-headers=${BUILDLINK_PREFIX.lzo}/include/lzo
CONFIGURE_ARGS+=	--with-lzo-lib=${BUILDLINK_PREFIX.lzo}/lib
BUILD_TARGET=		vtund

USE_TOOLS+=		yacc

DOCDIR=			${PREFIX}/share/doc/vtun
EGDIR=			${PREFIX}/share/examples/vtun
LOCKDIR=		/var/run/vtund
LOGDIR=			/var/log/vtund

CONF_FILES_PERMS=	${EGDIR}/vtund.conf ${PKG_SYSCONFDIR}/vtund.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
OWN_DIRS=		${LOCKDIR} ${LOGDIR}

INSTALLATION_DIRS=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin
INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR}

SUBST_CLASSES+=		fix-man
SUBST_STAGE.fix-man=	pre-configure
SUBST_MESSAGE.fix-man=	Fixing man pages.
SUBST_FILES.fix-man=	vtund.8
SUBST_VARS.fix-man=	PKG_SYSCONFDIR

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vtund ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.Setup ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.Shaper ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/vtund.conf ${DESTDIR}${EGDIR}/vtund.conf
	${INSTALL_MAN} ${WRKSRC}/vtund.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/vtund.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../net/solaris-tap/buildlink3.mk"
.endif

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
