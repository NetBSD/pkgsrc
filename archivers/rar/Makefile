# $NetBSD: Makefile,v 1.52 2009/05/19 08:59:00 wiz Exp $

DISTNAME=		rar	# overridden in Makefile.${EMUL_PLATFORM}
PKGNAME=		rar-2.02 # also overridden
PKGREVISION=		1
CATEGORIES=		archivers
MASTER_SITES=		# empty

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rarsoft.com/
COMMENT=		RAR file archiver (binary)
LICENSE=		rar-license

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

EMUL_PLATFORMS=		linux-i386 netbsd-i386

MESSAGE_SRC=		${PKGDIR}/MESSAGE.${EMUL_PLATFORM}

.include "../../mk/bsd.prefs.mk"

.if exists(Makefile.${EMUL_PLATFORM})
.  include "Makefile.${EMUL_PLATFORM}"
.else
NO_BUILD=		yes
do-install:		# nothing
.endif

.include "../../mk/bsd.pkg.mk"
