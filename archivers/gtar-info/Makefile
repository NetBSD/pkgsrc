# $NetBSD: Makefile,v 1.6 2002/02/18 15:14:01 seb Exp $
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

INFO_FILES=	tar.info

NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	for i in ${WRKSRC}/doc/tar.info* ; \
	do \
	    ${INSTALL_DATA} $${i} ${PREFIX}/info ; \
	done

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
