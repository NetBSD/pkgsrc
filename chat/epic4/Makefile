# $NetBSD: Makefile,v 1.3 2001/02/08 14:20:33 hubertf Exp $
#

DISTNAME=	epic4-0.9.16
CATEGORIES=	chat
MASTER_SITES=   ftp://ftp.epicsol.org/pub/epic/EPIC4-BETA/ \
		ftp://ftp.magenet.com/pub/epic/EPIC4-BETA/ \
		http://zuntum.eik.pl/pkgsrc/distfiles/
DISTFILES=	epic4-0.9.16.tar.gz \
		epic4pre2-help.tar.gz

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"
.if defined(USE_INET6) && ${USE_INET6} == "YES"
PATCH_SITES=    http://zuntum.eik.pl/patches/			\
		http://zuntum.invisible.yi.org/patches/		\
		http://flis.utech.lublin.pl/~zuntum/patches/
PATCHFILES=     epic4-0.9.16-ipv6-20010208.patch.gz
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://www.epicsol.org/

EXTRACT_ONLY=	epic4-0.9.16.tar.gz

GNU_CONFIGURE=	YES

.if defined(USE_INET6) && ${USE_INET6} == "YES"
BUILDS_DEPENDS+=	autoconf:../../devel/autoconf

post-patch:
		cd ${WRKSRC}; ${LOCALBASE}/bin/autoheader; ${LOCALBASE}/bin/autoconf
.endif

post-install:
		cd ${PREFIX}/share/epic && ( ${GUNZIP_CMD} -c ${DISTDIR}/epic4pre2-help.tar.gz | ${GTAR} xf - )

.include "../../mk/bsd.pkg.mk"
