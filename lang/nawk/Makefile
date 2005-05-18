# $NetBSD: Makefile,v 1.23 2005/05/18 05:22:43 jlam Exp $
#

DISTNAME=       awk
PKGNAME=        nawk-20050424
CATEGORIES=	lang
#MASTER_SITES=   http://cm.bell-labs.com/who/bwk/
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}
DIST_SUBDIR=	${PKGNAME}

# We use the .shar file instead of the .tar.gz file to avoid needing
# build dependencies.
#
EXTRACT_SUFX=	.shar

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://cm.bell-labs.com/who/bwk/
COMMENT=	Brian Kernighan's pattern-directed scanning and processing language

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"
.if empty(_USE_NEW_TOOLS:M[yY][eE][sS])
USE_GNU_TOOLS+=	yacc
.else
USE_TOOLS+=	yacc
.endif

WRKSRC=		${WRKDIR}
CFLAGS+=	${CPPFLAGS}
MAKE_FLAGS+=	CC=${CC:Q} YACC=${YACC:Q} CFLAGS=${CFLAGS:Q}
BUILD_TARGET=	a.out

INSTALLATION_DIRS=	bin man/man1

# Fix bug in distributed makefile with respect to improper makefile
# comments -- we simply just strip out all comments from the file.
#
do-configure:
	${SED} "s|^[ 	]*#.*||" ${WRKSRC}/makefile > ${WRKSRC}/${MAKEFILE}

# We want to install the man page as "nawk.1".
post-build:
	${SED} -e 's|awk|nawk|g' -e 's/Awk/Nawk/g' \
		${WRKSRC}/awk.1 > ${WRKSRC}/nawk.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nawk
	${INSTALL_MAN} ${WRKSRC}/nawk.1 ${PREFIX}/man/man1/nawk.1

.include "../../mk/bsd.pkg.mk"
