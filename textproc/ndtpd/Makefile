# $NetBSD: Makefile,v 1.29 2007/04/27 04:08:19 uebayasi Exp $
#

DISTNAME=	ndtpd-3.1.5
PKGREVISION=	5
CATEGORIES=	textproc japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/ndtpd/
COMMENT=	Server for accessing CD-ROM books with NDTP

PKG_INSTALLATION_TYPES=	pkgviews overwrite

USE_TOOLS+=	makeinfo perl:run
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

INFO_FILES=	# PLIST

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${NDTPD_RUNDIR:Q}
CONFIGURE_ARGS+=	--with-logdir=${NDTPD_LOGDIR:Q}
CONFIGURE_ARGS+=	--with-eb
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-eb-conf=${PKG_SYSCONFDIR}/eb.conf

CONFIGURE_ENV+=		ac_cv_path_BZIP2=bzip2
CONFIGURE_ENV+=		ac_cv_path_COMPRESS=compress
CONFIGURE_ENV+=		ac_cv_path_GZIPCMD=gzip

# For INSTALL/DEINSTALL scripts.
CONF_FILES=	${EGDIR}/ndtpd.conf.default ${PKG_SYSCONFDIR}/ndtpd.conf
RCD_SCRIPTS=	ndtpd

# Will be also used for ndtpd.sh.
FILES_SUBST+=	NDTPD_RUNDIR=${NDTPD_RUNDIR:Q}

EGDIR=		${PREFIX}/share/examples/ndtpd
NDTPD_LOGDIR=	/var/log
NDTPD_RUNDIR=	/var/run
# XXX NDTPD actually uses ${NDTPD_RUNDIR}/ndtpd.

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ndtpd.conf.sample \
		${EGDIR}/ndtpd.conf.default

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
