# $NetBSD: Makefile,v 1.15 2003/03/14 19:37:47 jlam Exp $

DISTNAME=	teapop-0.3.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.toontown.org/pub/teapop/			\
		http://www.toontown.org/pub/teapop/

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.toontown.org/teapop/
COMMENT=	Yet another RFC1939 compliant POP3 server

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-flock
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/teapop
CONF_FILES=	${EGDIR}/teapop.passwd ${PKG_SYSCONFDIR}/teapop.passwd

RCD_SCRIPTS=	teapop

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
LDFLAGS+=	${BUILDLINK_LDFLAGS.mysql-client}
.endif

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/teapop.passwd ${EGDIR}

.include "../../mk/bsd.pkg.mk"
