# $NetBSD: Makefile,v 1.9 2002/05/07 22:49:19 hubertf Exp $

DISTNAME=	teapop-0.3.4
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.toontown.org/pub/teapop/			\
		http://www.toontown.org/pub/teapop/

MAINTAINER=	dawszy@netbsd.org
HOMEPAGE=	http://www.toontown.org/teapop/
COMMENT=	Yet another RFC1939 compliant POP3 server

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-flock
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/teapop
CONF_FILES=	${EGDIR}/teapop.passwd ${PKG_SYSCONFDIR}/teapop.passwd

.include "../../mk/bsd.prefs.mk"

.if defined(TEAPOP_WITHOUT_APOP)
CONFIGURE_ARGS+=--disable-apop
.endif

.if defined(TEAPOP_WITHOUT_VPOP)
CONFIGURE_ARGS+=--disable-vpop
.endif

.if defined(TEAPOP_WITH_MYSQL)
DEPENDS+=      mysql-client>=3.23:../../databases/mysql-client
CONFIGURE_ARGS+=       --with-mysql=${LOCALBASE}
LDFLAGS+=      -L${LOCALBASE}/lib/mysql -Wl,-R${LOCALBASE}/lib/mysql
.endif

post-build:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/teapop > ${WRKDIR}/teapop

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/teapop.passwd ${EGDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/teapop ${PREFIX}/etc/rc.d/teapop

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
