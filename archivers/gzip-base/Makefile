# $NetBSD: Makefile,v 1.13 2003/07/17 21:21:17 grant Exp $
#

DISTNAME=	gzip-1.2.4a
PKGNAME=	${DISTNAME:S/gzip-/gzip-base-/}
PKGREVISION=	1
SVR4_PKGNAME=	gzipb
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Compress or expand files

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

BUILD_TARGET=	all manlinks=so
INSTALL_TARGET=	install manlinks=so

do-patch:
	f=${WRKSRC}/Makefile.in ; \
	[ -f $$f.orig ] || ${CP} $$f $$f.orig ; \
	${SED} \
		'/scriptdir/s/INSTALL_PROGRAM/BSD_INSTALL_SCRIPT/' \
		< $$f.orig >$$f

# We avoid using a patch for disabling the install of the info
# file.  The easy part is that "install-info" is not called so
# we can simply remove the single installed info file.

post-install:
	-${RM} -f ${PREFIX}/info/gzip.info

.include "../../mk/bsd.pkg.mk"
