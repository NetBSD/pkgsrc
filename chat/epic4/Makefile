# $NetBSD: Makefile,v 1.16 2002/05/03 15:52:11 zuntum Exp $
#

DISTNAME=	epic4-1.0.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/	\
		ftp://ftp.icm.edu.pl/pub/unix/irc/EPIC/EPIC4-PRODUCTION/ \
		ftp://ftp.archive.de.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/	\
		ftp://ftp.nl.uu.net/pub/unix/irc/epic/EPIC4-PRODUCTION/
EXTRACT_SUFX=	.tar.bz2

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"
.if defined(USE_INET6) && ${USE_INET6} == "YES"
PATCH_SITES=    http://www.t17.ds.pwr.wroc.pl/~misiek/ipv6/
PATCHFILES=     epic4-1.0.1-ipv6-20010418.patch.gz
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

GNU_CONFIGURE=	YES

.if defined(USE_INET6) && ${USE_INET6} == "YES"
BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf

post-patch:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoheader; ${LOCALBASE}/bin/autoconf
.endif

.include "../../mk/bsd.pkg.mk"
