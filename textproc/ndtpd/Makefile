# $NetBSD: Makefile,v 1.6 2003/02/06 04:24:13 uebayasi Exp $

DISTNAME=	ndtpd-3.1.4
CATEGORIES=	textproc japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/ndtpd/
COMMENT=	Server for accessing CD-ROM books with NDTP

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir=${NDTPD_RUNDIR}
CONFIGURE_ARGS+=--with-logdir=${NDTPD_LOGDIR}
CONFIGURE_ARGS+=--with-eb
CONFIGURE_ARGS+=--with-zlib
MAKE_FLAGS+=	INSTALL_INFO=${INSTALL_INFO}
# For INSTALL/DEINSTALL scripts.
CONF_FILES=	${NDTPD_CONFDIR}/ndtpd.conf.sample ${NDTPD_CONFDIR}/ndtpd.conf
RCD_SCRIPT=	ndtpd.sh
# Will be also used for ndtpd.sh.
FILES_SUBST+=	NDTPD_RUNDIR=${NDTPD_RUNDIR}

NDTPD_CONFDIR=	${PREFIX}/etc
NDTPD_LOGDIR=	${DESTDIR}/var/log
NDTPD_RUNDIR=	${DESTDIR}/var/run
# XXX NDTPD actually uses ${NDTPD_RUNDIR}/ndtpd.

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/ndtpd.sh >${WRKDIR}/ndtpd.sh

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/ndtpd.sh ${PREFIX}/etc/rc.d/ndtpd.sh

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/eb/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
