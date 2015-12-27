# $NetBSD: Makefile,v 1.33 2015/12/27 12:16:33 adam Exp $
#
# In order to ensure compliance with U.S. and international law, please
# do not modify this file to provide pointers to the source or homepage
# for this software or submit any PRs telling us the contents of the
# HOMEPAGE or MASTER_SITES definitions in this Makefile.

DISTNAME=	libdvdcss-1.4.0
CATEGORIES=	multimedia
MASTER_SITES=	${LIBDVDCSS_MASTER_SITES}/${DISTNAME:S/libdvdcss-//}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${LIBDVDCSS_HOMEPAGE}
COMMENT=	Simple library designed for accessing DVDs
LICENSE=	gnu-gpl-v2

RESTRICTED=	Legal problems due to CSS code
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

PKGCONFIG_OVERRIDE=	src/libdvdcss.pc.in

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doc
CONFIGURE_ENV+=		ac_cv_path_DOXYGEN=

.include "../../mk/bsd.prefs.mk"

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(LIBDVDCSS_MASTER_SITES)
PKG_FAIL_REASON+=	"Please define LIBDVDCSS_MASTER_SITES in mk.conf."
PKG_FAIL_REASON+=	"Alternatively you may download '${DISTNAME}${EXTRACT_SUFX}' manually"
PKG_FAIL_REASON+=	"to ${DISTDIR}."
.endif

.include "../../mk/bsd.pkg.mk"
