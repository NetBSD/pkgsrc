# $NetBSD: Makefile,v 1.3.12.1 2009/10/22 11:03:18 tron Exp $
#

DISTNAME=	nbpatch-20091021
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Patch files using diff output

PKG_DESTDIR_SUPPORT=	user-destdir

# Allow checkperms and othher core dependencies to use patches
CHECK_PERMS=		no

USE_BSD_MAKEFILE=	yes
USE_FEATURES=		nbcompat

NBCOMPAT_CONFIGURE_ARGS+=	--enable-bsd-getopt

ALL_ENV+=	LDADD=${LIBS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
