# $NetBSD: Makefile,v 1.10 2001/03/29 10:48:34 wennmach Exp $
#

DISTNAME=	epic4-0.10.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.magenet.com/pub/epic/EPIC4-BETA/		\
		ftp://ftp.icm.edu.pl/vol/rzm0/irc/EPIC/EPIC4-BETA/	\
		ftp://ftp.archive.de.uu.net/pub/unix/irc/epic/EPIC4-BETA/ \
		ftp://ftp.nl.uu.net/pub/unix/irc/epic/EPIC4-BETA/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}				\
		epic4pre2-help.tar.gz

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"
.if defined(USE_INET6) && ${USE_INET6} == "YES"
PATCH_SITES=    http://www.t17.ds.pwr.wroc.pl/~misiek/ipv6/		\
		http://zuntum.net/patches/				\
		http://flis.utech.lublin.pl/~zuntum/patches/
PATCHFILES=     epic4-0.9.16-ipv6-20010217.patch.gz
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

GNU_CONFIGURE=	YES

.if defined(USE_INET6) && ${USE_INET6} == "YES"
BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf

post-patch:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoheader; ${LOCALBASE}/bin/autoconf
.endif

post-install:
	cd ${PREFIX}/share/epic &&					\
	( ${GUNZIP_CMD} -c ${DISTDIR}/epic4pre2-help.tar.gz | ${GTAR} xf - )

.include "../../mk/bsd.pkg.mk"
