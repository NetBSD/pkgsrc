# $NetBSD: Makefile,v 1.2 2002/03/15 17:15:03 uebayasi Exp $

DISTNAME=	ndtpd-3.1.1
CATEGORIES=	textproc japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/

PATCHFILES=	${DISTNAME}+.diff
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/ndtpd/
COMMENT=	Server for accessing CD-ROM books with NDTP

USE_BUILDLINK_ONLY=	# Defined
USE_LIBTOOL=	# Defined
GNU_CONFIGURE=	# Defined
CONFIGURE_ARGS+=--localstatedir=${NDTPD_RUNDIR}
CONFIGURE_ARGS+=--with-logdir=${NDTPD_LOGDIR}
CONFIGURE_ARGS+=--with-eb
CONFIGURE_ARGS+=--with-eb-includes=${PREFIX}/include
CONFIGURE_ARGS+=--with-eb-libraries=${PREFIX}/lib
CONFIGURE_ARGS+=--with-zlib
MAKE_FLAGS+=	INSTALL_INFO=${INSTALL_INFO}
# For INSTALL/DEINSTALL scripts.
CONF_FILES=	${NDTPD_CONFDIR}/ndtpd.conf.sample ${NDTPD_CONFDIR}/ndtpd.conf
OWN_DIRS=	${NDTPD_RUNDIR}/ndtpd
RCD_SCRIPT=	ndtpd.sh
# Will be used not only for INSTALL but also ndtpd.sh.
FILES_SUBST+=	NDTPD_RUNDIR=${NDTPD_RUNDIR:Q}

NDTPD_CONFDIR=	${PREFIX}/etc
NDTPD_LOGDIR=	${DESTDIR}/var/log
NDTPD_RUNDIR=	${DESTDIR}/var/run

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/ndtpd.sh >${WRKDIR}/ndtpd.sh

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/ndtpd.sh ${PREFIX}/etc/rc.d/ndtpd.sh

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../textproc/eb/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
