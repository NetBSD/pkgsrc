# $NetBSD: Makefile,v 1.21 2006/03/30 03:44:43 jlam Exp $

DISTNAME=	rx-1.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	#
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/rx/rx.html
COMMENT=	Fast replacement for the GNU regex library

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	# PLIST

# When the API changes and breaks binary-compatibility with the previous
# version, increment the MAJOR by 1 and reset the MINOR to 0.  Otherwise,
# bump the MINOR when a new version comes out.
#
RX_MAJOR=	0
RX_MINOR=	0
MAKE_ENV+=	RX_MAJOR=${RX_MAJOR:Q} RX_MINOR=${RX_MINOR:Q}

INSTALLATION_DIRS=	${PKGINFODIR}

post-install:
	cd ${WRKSRC}/doc; for f in rx.info rx.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done

.include "../../mk/bsd.pkg.mk"
