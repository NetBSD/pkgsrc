# $NetBSD: Makefile,v 1.1.1.1 2002/11/07 23:18:01 atatat Exp $
#

DISTNAME=	pkgdepgraph-1.0
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	atatat@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Visual representation of installed NetBSD packages

DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

USE_PERL5=	YES

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

MAKE_ENV=	PKG_DBDIR=${PKG_DBDIR}

DISTVER=	${DISTNAME:S/pkgdepgraph-//}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# This doesn't create readable manual pages. "mandoc" should be added
# to zoularis.
NROFF=		nroff -man
.else
NROFF=		nroff -mandoc
.endif

do-build:
.for FILE in pkgdepgraph
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'	\
		-e 's|@DISTVER@|${DISTVER}|g'		\
		< ${FILESDIR}/${FILE}.pl 		\
		> ${WRKSRC}/${FILE}
.endfor
.for FILE in pkgdepgraph
	${SED} -e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'	\
		< ${FILESDIR}/${FILE}.1			\
		> ${WRKSRC}/${FILE}.1
	${NROFF} ${WRKSRC}/${FILE}.1 >${WRKSRC}/${FILE}.0
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgdepgraph ${PREFIX}/bin/pkgdepgraph
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
