# $NetBSD: Makefile,v 1.2 2000/12/30 11:43:06 hubertf Exp $
#

DISTNAME=	epic4-0.9.15
CATEGORIES=	chat
MASTER_SITES=   ftp://ftp.epicsol.org/pub/epic/EPIC4-BETA/ \
		ftp://ftp.magenet.com/pub/epic/EPIC4-BETA/ \
		http://zuntum.eik.pl/pkgsrc/distfiles/
DISTFILES=	epic4-0.9.15.tar.gz \
		epic4pre2-help.tar.gz

.if defined(USE_INET6) && ${USE_INET6} == "YES"
PATCH_SITES=    http://zuntum.eik.pl/patches/ \
		http://zuntum.invisible.yi.org/patches/
PATCHFILES=     epic4-0.9.15-ipv6-netbsd-20001230.patch.bz2
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://www.epicsol.org/

EXTRACT_ONLY=	epic4-0.9.15.tar.gz

GNU_CONFIGURE=	YES

post-install:
		cd ${PREFIX}/share/epic && ( ${GUNZIP_CMD} -c ${DISTDIR}/epic4pre2-help.tar.gz | ${GTAR} xf - )

.include "../../mk/bsd.pkg.mk"
