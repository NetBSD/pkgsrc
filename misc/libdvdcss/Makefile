# $NetBSD: Makefile,v 1.3 2003/02/12 14:52:00 agc Exp $
#
# Unfortunately, some reading of the United States law (DMCA) means
# that we are not able to provide pointers to the source or homepage
# for this software, even in other countries.
#
# Please do not submit any PRs telling us the contents of the HOMEPAGE
# or MASTER_SITES definitions in this Makefile.

DISTNAME=	libdvdcss-1.2.4
CATEGORIES=	misc
MASTER_SITES=	${LIBDVDCSS_MASTER_SITES}

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	${LIBDVDCSS_HOMEPAGE}
COMMENT=	simple library designed for accessing DVDs

RESTRICTED=	Legal problems due to css code

# no source because of the css source code in it
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
