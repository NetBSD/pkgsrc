# $NetBSD: Makefile,v 1.6 2001/12/02 06:56:42 jlam Exp $

DISTNAME=	teapop-0.3.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.toontown.org/pub/teapop/			\
		http://www.toontown.org/pub/teapop/

MAINTAINER=	packages@netbsd.org
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

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/teapop.passwd ${EGDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
