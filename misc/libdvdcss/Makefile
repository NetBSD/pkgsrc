# $NetBSD: Makefile,v 1.1.1.1 2003/01/22 13:51:23 agc Exp $
#
# Unfortunately, some reading of the United States law (DMCA) means
# that we are not able to provide pointers to the source or homepage
# for this software, even in other countries.
#
# Please do not submit any PRs telling us the contents of the HOMEPAGE
# or MASTER_SITES definitions in this Makefile.

DISTNAME=	libdvdcss-1.2.4
CATEGORIES=	misc
MASTER_SITES=	# defined - see comment above

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	# defined - see comment above
COMMENT=	simple library designed for accessing DVDs

# no source on the ftp server because of the css source code in it
NO_SRC_ON_FTP=		${RESTRICTED}

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
