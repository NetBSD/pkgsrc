# $NetBSD: Makefile,v 1.15 2004/04/24 22:46:09 jlam Exp $

DISTNAME=	rx-1.5
CATEGORIES=	devel
MASTER_SITES=	#
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/rx/rx.html
COMMENT=	Fast replacement for the GNU regex library

USE_BUILDLINK3=	yes
USE_LIBTOOL=	# defined
GNU_CONFIGURE=	# defined

INFO_FILES=	rx.info

# When the API changes and breaks binary-compatibility with the previous
# version, increment the MAJOR by 1 and reset the MINOR to 0.  Otherwise,
# bump the MINOR when a new version comes out.
#
RX_MAJOR=	0
RX_MINOR=	0
MAKE_ENV+=	RX_MAJOR="${RX_MAJOR}" RX_MINOR="${RX_MINOR}"

post-install:
	cd ${WRKSRC}/doc; ${INSTALL_DATA} ${INFO_FILES} ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
