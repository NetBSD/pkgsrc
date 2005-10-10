# $NetBSD: Makefile,v 1.13 2005/10/10 21:54:31 agc Exp $
#
# In order to ensure compliance with U.S. and international law, please
# do not modify this file to provide pointers to the source or homepage
# for this software or submit any PRs telling us the contents of the
# HOMEPAGE or MASTER_SITES definitions in this Makefile.

DISTNAME=	libdvdcss-1.2.9
CATEGORIES=	multimedia
MASTER_SITES=	${LIBDVDCSS_MASTER_SITES}/${DISTNAME:S/libdvdcss-//}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	${LIBDVDCSS_HOMEPAGE}
COMMENT=	Simple library designed for accessing DVDs

RESTRICTED=	Legal problems due to CSS code

# no source because of the CSS source code in it
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
