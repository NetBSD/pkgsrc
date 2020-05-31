# $NetBSD: Makefile,v 1.48 2020/05/31 17:34:15 rillig Exp $

DISTNAME=	teapop-0.3.8
PKGREVISION=	19
CATEGORIES=	mail
MASTER_SITES=	# ftp://ftp.toontown.org/pub/teapop/

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	http://www.toontown.org/teapop/
COMMENT=	Yet another RFC1939 compliant POP3 server

USE_TOOLS+=	perl:run

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-piddir=${VARBASE}/run

EGDIR=		${PREFIX}/share/examples/teapop
CONF_FILES=	${EGDIR}/teapop.passwd ${PKG_SYSCONFDIR}/teapop.passwd

RCD_SCRIPTS=	teapop

.include "options.mk"

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/teapop.passwd ${DESTDIR}${EGDIR}

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
