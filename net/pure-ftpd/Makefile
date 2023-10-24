# $NetBSD: Makefile,v 1.44 2023/10/24 22:10:31 wiz Exp $

DISTNAME=	pure-ftpd-1.0.49
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://download.pureftpd.org/pub/pure-ftpd/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pureftpd.org/project/pure-ftpd
COMMENT=	Secure FTP daemon with optional SQL support
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-everything
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS.Interix+=	--without-privsep

CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600

RCD_SCRIPTS=		pure_ftpd pure_uploadscript

EGDIR=			${PREFIX}/share/examples/pure-ftpd

CONF_FILES+=		${EGDIR}/pure-ftpd.conf \
			${PKG_SYSCONFDIR}/pure-ftpd.conf
.include "options.mk"
.include "../../mk/bsd.pkg.mk"
