# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:01 veego Exp $
#

DISTNAME=       tar-1.12
PKGNAME=	gtar-info-1.12
SVR4_PKGNAME=	gtari
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=tar/}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	Info format documentation for the GNU tape archiver

EXTRACT_CMD=	${DECOMPRESS_CMD} ${DOWNLOADED_DISTFILE} | ${SH}

USE_GTEXINFO=	yes
INFO_FILES=	tar.info

NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	for i in ${WRKSRC}/doc/tar.info* ; \
	do \
	    ${INSTALL_DATA} $${i} ${PREFIX}/info ; \
	done

.include "../../mk/bsd.pkg.mk"
