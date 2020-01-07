# $NetBSD: Makefile,v 1.14 2020/01/07 12:30:48 kim Exp $
#

DISTNAME=	psify-19980216
CATEGORIES=	print
MASTER_SITES=	${HOMEPAGE}
DISTFILES=	Makefile psify.c psify.lex psify.man

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stuff.mit.edu/afs/athena/system/pmax_ul4/srvd.74/usr/sipb/src/psify/
		#                         ^^^^^^
		# Note that this is the Athena modified version of psify, which includes
		# support for SCHEME and Java source files, and for rendering reserved words
		# in comments with a separate font.
		#
		# If you update the HOMEPAGE, please make sure that the downloaded source
		# files are in fact the correct ones.
		#
COMMENT=	Pretty print C, CLU, SCHEME, Java and ARGUS source files

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	psify
EXTRACT_ONLY=	#empty

NO_CONFIGURE=	yes
USE_TOOLS+=	lex

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

post-extract:
	for i in ${DISTFILES}; do \
		${CP} ${_DISTDIR}/$$i ${WRKSRC}; \
	done

.include "../../mk/bsd.pkg.mk"
