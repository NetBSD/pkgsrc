# $NetBSD: Makefile,v 1.4 2004/10/03 00:13:02 tv Exp $
#
# Unfortunately, some reading of the United States law (DMCA) means
# that we are not able to provide pointers to the source or homepage
# for this software, even in other countries.
#
# Please do not submit any PRs telling us the contents of the HOMEPAGE
# or MASTER_SITES definitions in this Makefile.

DISTNAME=	libdvdcss-1.2.8
PKGREVISION=	1
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

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
