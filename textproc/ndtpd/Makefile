# $NetBSD: Makefile,v 1.19 2005/12/05 20:51:07 rillig Exp $
#

DISTNAME=	ndtpd-3.1.5
PKGREVISION=	2
CATEGORIES=	textproc japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/ndtpd/
COMMENT=	Server for accessing CD-ROM books with NDTP

PKG_INSTALLATION_TYPES=	pkgviews overwrite

USE_PKGINSTALL=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

INFO_FILES=	ndtpd-ja.info ndtpd.info

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${NDTPD_RUNDIR}
CONFIGURE_ARGS+=	--with-logdir=${NDTPD_LOGDIR}
CONFIGURE_ARGS+=	--with-eb
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-eb-conf=${PKG_SYSCONFDIR.eb}/eb.conf

# For INSTALL/DEINSTALL scripts.
CONF_FILES=	${EGDIR}/ndtpd.conf.default ${PKG_SYSCONFDIR}/ndtpd.conf
RCD_SCRIPTS=	ndtpd

# Will be also used for ndtpd.sh.
FILES_SUBST+=	NDTPD_RUNDIR=${NDTPD_RUNDIR:Q}

EGDIR=		${PREFIX}/share/examples/ndtpd
NDTPD_LOGDIR=	${DESTDIR}/var/log
NDTPD_RUNDIR=	${DESTDIR}/var/run
# XXX NDTPD actually uses ${NDTPD_RUNDIR}/ndtpd.

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ndtpd.conf.sample \
		${EGDIR}/ndtpd.conf.default

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
