# $NetBSD: Makefile,v 1.36 2008/06/19 18:36:51 joerg Exp $

DISTNAME=		pax-20080110
CATEGORIES=		archivers
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		POSIX standard archiver with many extensions

PKG_DESTDIR_SUPPORT=	user-destdir
BOOTSTRAP_PKG=	yes

USE_FEATURES=		nbcompat

.include "../../mk/bsd.prefs.mk"

# pax installs "tar" and "cpio"
.if defined(GNU_PROGRAM_PREFIX) && empty(GNU_PROGRAM_PREFIX)
CONFLICTS+=		gcpio-[0-9]*
.endif
.if defined(GTAR_PROGRAM_PREFIX) && empty(GTAR_PROGRAM_PREFIX)
CONFLICTS+=		gtar-base-[0-9]*
.endif

GNU_CONFIGURE=		yes
NO_CHECKSUM=		yes

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
