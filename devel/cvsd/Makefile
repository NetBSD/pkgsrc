# $NetBSD: Makefile,v 1.20 2019/08/11 13:18:41 wiz Exp $

DISTNAME=		cvsd-1.0.23
PKGREVISION=		9
CATEGORIES=		devel scm
MASTER_SITES=		https://arthurdejong.org/cvsd/

MAINTAINER=		eric@cirr.com
HOMEPAGE=		https://arthurdejong.org/cvsd/
COMMENT=		Run CVS pserver in a chroot-ed environment
LICENSE=		gnu-gpl-v2

.if !exists(/usr/bin/cvs)
DEPENDS+=   		cvs>=1.11:../../devel/scmcvs
.endif

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
PKG_GROUPS_VARS+=	CVSD_GROUP
PKG_USERS_VARS+=	CVSD_USER

INSTALLATION_DIRS=	${EGDIR}

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${EGDIR}

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
