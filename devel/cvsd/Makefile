# $NetBSD: Makefile,v 1.4 2006/09/06 19:04:59 wiz Exp $

DISTNAME=		cvsd-1.0.13
CATEGORIES=		devel
MASTER_SITES=		http://ch.tudelft.nl/~arthur/cvsd/

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://ch.tudelft.nl/~arthur/cvsd/
COMMENT=		Run CVS pserver in a chroot-ed environment

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-libwrap

RCD_SCRIPTS=		cvsd

EGDIR=			${PREFIX}/share/examples/cvsd
CONF_FILES=		${EGDIR}/cvsd.conf.example ${PKG_SYSCONFDIR}/cvsd.conf

CVSD_USER?=		cvsd
CVSD_GROUP?=		cvsd
PKG_USERS=		${CVSD_USER}:${CVSD_GROUP}
PKG_GECOS.${CVSD_USER}=	CVS wrapper
PKG_GROUPS=		${CVSD_GROUP}

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
