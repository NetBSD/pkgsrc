# $NetBSD: Makefile,v 1.26 2006/01/08 18:35:10 xtraeme Exp $

DISTNAME=	teapop-0.3.8
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.toontown.org/pub/teapop/			\
		http://www.toontown.org/pub/teapop/

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.toontown.org/teapop/
COMMENT=	Yet another RFC1939 compliant POP3 server

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-flock
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-piddir=${VARBASE}/run

EGDIR=		${PREFIX}/share/examples/teapop
CONF_FILES=	${EGDIR}/teapop.passwd ${PKG_SYSCONFDIR}/teapop.passwd

RCD_SCRIPTS=	teapop

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/teapop.passwd ${EGDIR}

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
