# $NetBSD: Makefile,v 1.11 2003/04/30 03:39:17 atatat Exp $
#

DISTNAME=	pkgdepgraph-2.5
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	atatat@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Visual representation of installed NetBSD packages

# removed so that pkgdepgraph can be used on "client" machines -- @@@
# DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

USE_PERL5=	YES

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

DISTVER=	${DISTNAME:S/pkgdepgraph-//}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# This doesn't create readable manual pages. "mandoc" should be added
# to zoularis.
NROFF=		nroff -man
.else
NROFF=		nroff -mandoc
.endif

do-extract:
	${CP} ${FILESDIR}/pkgdepgraph.pl ${WRKSRC}/pkgdepgraph.pl
	${CP} ${FILESDIR}/pkgdepgraph.1 ${WRKSRC}/pkgdepgraph.1.in

do-build:
.for FILE in pkgdepgraph
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'	\
		-e 's|@PKGSRCDIR@|${_PKGSRCDIR}|g'	\
		-e 's|@DISTVER@|${DISTVER}|g'		\
		< ${WRKSRC}/${FILE}.pl 		\
		> ${WRKSRC}/${FILE}
.endfor
.for FILE in pkgdepgraph
	${SED} -e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'	\
		-e 's|@PKGSRCDIR@|${_PKGSRCDIR}|g'	\
		< ${WRKSRC}/${FILE}.1.in		\
		> ${WRKSRC}/${FILE}.1
	${NROFF} ${WRKSRC}/${FILE}.1 >${WRKSRC}/${FILE}.0
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgdepgraph ${PREFIX}/bin/pkgdepgraph
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.1 ${PREFIX}/man/man1

post-install:
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
