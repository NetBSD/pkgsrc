# $NetBSD: Makefile,v 1.6.8.1 2002/12/22 08:29:20 agc Exp $
#

DISTNAME=       tar-1.13.25
PKGNAME=	gtar-info-1.13.25
SVR4_PKGNAME=	gtari
CATEGORIES=	archivers
MASTER_SITES=	ftp://alpha.gnu.org/gnu/tar/ \
		ftp://ftp.sunsite.org.uk/Mirrors/alpha.gnu.org/gnu/tar/ \
		ftp://ftp.funet.fi/pub/mirrors/alpha.gnu.org/gnu/tar/

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
