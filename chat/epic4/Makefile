# $NetBSD: Makefile,v 1.14 2001/09/15 13:49:51 zuntum Exp $
#

DISTNAME=	epic4-1.0.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/	\
		ftp://ftp.icm.edu.pl/pub/unix/irc/EPIC/EPIC4-PRODUCTION/ \
		ftp://ftp.archive.de.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/	\
		ftp://ftp.nl.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/	\
		ftp://ftp.epicsol.org/pub/epic/EPIC4-BETA/		\
		ftp://ftp.icm.edu.pl/pub/unix/irc/EPIC/EPIC4-BETA/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}				\
		epic4pre2-help.tar.gz

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"
.if defined(USE_INET6) && ${USE_INET6} == "YES"
PATCH_SITES=    http://www.t17.ds.pwr.wroc.pl/~misiek/ipv6/		\
		http://zuntum.utech.lublin.pl/patches/
PATCHFILES=     epic4-1.0.1-ipv6-20010418.patch.gz
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

GNU_CONFIGURE=	YES

.if defined(USE_INET6) && ${USE_INET6} == "YES"
BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf

post-patch:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoheader; ${LOCALBASE}/bin/autoconf
.endif

post-install:
	cd ${PREFIX}/share/epic &&					\
	( ${GUNZIP_CMD} -c ${DISTDIR}/epic4pre2-help.tar.gz | ${GTAR} xf - )

.include "../../mk/bsd.pkg.mk"
