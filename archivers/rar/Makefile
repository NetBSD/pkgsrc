# $NetBSD: Makefile,v 1.47 2007/08/22 16:43:33 jlam Exp $

DISTNAME=		rar	# overridden in Makefile.${EMUL_PLATFORM}
CATEGORIES=		archivers
MASTER_SITES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rarsoft.com/
COMMENT=		RAR file archiver (binary)

EMUL_PLATFORMS=		linux-i386 netbsd-i386

LICENSE=		rar-license
RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

MESSAGE_SRC=		${PKGDIR}/MESSAGE.${EMUL_PLATFORM}

.include "../../mk/bsd.prefs.mk"

.if exists(Makefile.${EMUL_PLATFORM})
.  include "Makefile.${EMUL_PLATFORM}"
.else
NO_BUILD=		yes
do-install:		# nothing
.endif

.include "../../mk/bsd.pkg.mk"
