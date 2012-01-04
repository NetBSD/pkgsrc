# $NetBSD: Makefile,v 1.18 2012/01/04 15:09:38 dholland Exp $
#

DISTNAME=		sdbm
# this is the Dec. 1990 release with some race condition fixes from an
# unknown outside source:
PKGNAME=		sdbm-90.12.1
PKGREVISION=		2
CATEGORIES=		databases
MASTER_SITES=		# ftp://tsx-11.mit.edu/pub/linux/sources/libs/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Substitute DBM, an implementation of the "real" ndbm library

WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

post-extract:
	@cd ${WRKDIR} && ${SH} sdbm.shar >/dev/null

.include "../../mk/bsd.pkg.mk"
