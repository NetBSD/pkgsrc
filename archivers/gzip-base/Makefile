# $NetBSD: Makefile,v 1.9 2002/01/27 18:32:33 jlam Exp $

DISTNAME=	gzip-1.2.4a
PKGNAME=	gzip-base-1.2.4a
SVR4_PKGNAME=	gzipb
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Compress or expand files

GNU_CONFIGURE=	yes
BUILD_TARGET=	all manlinks=so
INSTALL_TARGET=	install manlinks=so

.if exists(/usr/bin/gzip)
IGNORE=		"${PKGNAME} is part of your ${OPSYS} distribution"
.endif

# We avoid using a patch for disabling the install of the info
# file.  The easu part is that "install-info" is not called so
# we can simply remove the single installed info file.

do-patch:
	f=${WRKSRC}/Makefile.in ; \
	[ -f $$f.orig ] || ${CP} $$f $$f.orig ; \
	${SED} \
		'/scriptdir/s/INSTALL_PROGRAM/INSTALL_DATA/' \
		< $$f.orig >$$f

post-install:
	-${RM} -f ${PREFIX}/info/gzip.info

.include "../../mk/bsd.pkg.mk"
