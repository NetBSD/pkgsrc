# $NetBSD: Makefile,v 1.5 2000/10/24 19:18:27 hubertf Exp $
#

DISTNAME=	gzip-1.2.4a
PKGNAME=	gzip-base-1.2.4a
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html

EXTRACT_CMD=	${SH} ${DOWNLOADED_DISTFILE}

GNU_CONFIGURE=	yes
BUILD_TARGET=	all manlinks=so
INSTALL_TARGET=	install manlinks=so

.if exists(/usr/bin/gzip)
IGNORE=		"${PKGNAME} is part of your NetBSD distribution"
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
