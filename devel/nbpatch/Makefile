# $NetBSD: Makefile,v 1.10 2015/11/07 18:29:50 joerg Exp $
#

DISTNAME=	nbpatch-20151107
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Patch files using diff output

# Allow checkperms and other core dependencies to use patches
CHECK_PERMS=		no

USE_BSD_MAKEFILE=	yes
USE_FEATURES=		nbcompat

NBCOMPAT_CONFIGURE_ARGS+=	--enable-bsd-getopt

LIBS.IRIX+=	-lgen
ALL_ENV+=	LDADD=${LIBS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

UAC_REQD_EXECS+=	bin/nbpatch
.include "../../mk/bsd.pkg.mk"
