# $NetBSD: Makefile,v 1.1.1.1 2000/01/17 03:44:27 jlam Exp $

DISTNAME=	rx-1.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=rx/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/rx/rx.html

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

INFO_FILES=	rx.info

# When the API changes and breaks binary-compatibility with the previous
# version, increment the MAJOR by 1 and reset the MINOR to 0.  Otherwise,
# bump the MINOR when a new version comes out.
#
RX_MAJOR=	0
RX_MINOR=	0
MAKE_ENV+=	RX_MAJOR="${RX_MAJOR}" RX_MINOR="${RX_MINOR}"

ALL_TARGET=	all info

post-install:
	cd ${WRKSRC}/doc; ${INSTALL_DATA} ${INFO_FILES} ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
