# $NetBSD: Makefile,v 1.8 2002/08/31 14:34:59 wiz Exp $

DISTNAME=	rx-1.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=rx/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/rx/rx.html
COMMENT=	Fast replacement for the GNU regex library

USE_BUILDLINK2=	# defined
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

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
