# $NetBSD: Makefile,v 1.7 2003/04/13 01:29:42 salo Exp $
#

DISTNAME=	ndtpd-3.1.4
PKGREVISION=	1
CATEGORIES=	textproc japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/ndtpd/
COMMENT=	Server for accessing CD-ROM books with NDTP

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${NDTPD_RUNDIR}
CONFIGURE_ARGS+=	--with-logdir=${NDTPD_LOGDIR}
CONFIGURE_ARGS+=	--with-eb
CONFIGURE_ARGS+=	--with-zlib

# For INSTALL/DEINSTALL scripts.
CONF_FILES=	${EGDIR}/ndtpd.conf.default ${PKG_SYSCONFDIR}/ndtpd.conf
RCD_SCRIPTS=	ndtpd

# Will be also used for ndtpd.sh.
FILES_SUBST+=	NDTPD_RUNDIR=${NDTPD_RUNDIR}

EGDIR=		${PREFIX}/share/examples/ndtpd
NDTPD_LOGDIR=	${DESTDIR}/var/log
NDTPD_RUNDIR=	${DESTDIR}/var/run
# XXX NDTPD actually uses ${NDTPD_RUNDIR}/ndtpd.

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ndtpd.conf.sample \
		${EGDIR}/ndtpd.conf.default

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/eb/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
