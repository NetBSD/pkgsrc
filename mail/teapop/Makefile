# $NetBSD: Makefile,v 1.12 2002/10/09 18:57:11 wiz Exp $

DISTNAME=	teapop-0.3.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.toontown.org/pub/teapop/			\
		http://www.toontown.org/pub/teapop/

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.toontown.org/teapop/
COMMENT=	Yet another RFC1939 compliant POP3 server

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-flock
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/teapop
CONF_FILES=	${EGDIR}/teapop.passwd ${PKG_SYSCONFDIR}/teapop.passwd

.include "../../mk/bsd.prefs.mk"

.if defined(POP_WITH_DRAC)
.include "../../mail/drac/buildlink2.mk"
CONFIGURE_ARGS+=	--with-drac=${BUILDLINK_PREFIX.drac}/lib
CONFIGURE_ARGS+=	--with-dracinc=${BUILDLINK_PREFIX.drac}/include
.endif

.if defined(TEAPOP_WITHOUT_APOP)
CONFIGURE_ARGS+=--disable-apop
.endif

.if defined(TEAPOP_WITHOUT_VPOP)
CONFIGURE_ARGS+=--disable-vpop
.endif

.if defined(TEAPOP_WITH_MYSQL)
.include "../../databases/mysql-client/buildlink2.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
LDFLAGS+=	-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql -Wl,-R${BUILDLINK_PREFIX.mysql-client}/lib/mysql
.endif

post-build:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/teapop > ${WRKDIR}/teapop

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/teapop.passwd ${EGDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/teapop ${PREFIX}/etc/rc.d/teapop

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
