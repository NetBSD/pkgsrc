# $NetBSD: Makefile,v 1.28 2012/09/11 23:19:38 asau Exp $
#

DISTNAME=	pkgdepgraph-2.8
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Visual representation of installed NetBSD packages

# removed so that pkgdepgraph can be used on "client" machines -- @@@
# DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run

NO_CONFIGURE=	yes

DISTVER=	${DISTNAME:S/pkgdepgraph-//}

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	${CP} ${FILESDIR}/pkgdepgraph.pl ${WRKSRC}/pkgdepgraph.pl
	${CP} ${FILESDIR}/pkgdepgraph.1 ${WRKSRC}/pkgdepgraph.1.in
	${CP} ${FILESDIR}/pkgdepgraph.0 ${WRKSRC}/pkgdepgraph.0.in

do-build:
.for FILE in pkgdepgraph
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'	\
		-e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'	\
		-e 's|@DISTVER@|${DISTVER}|g'		\
		< ${WRKSRC}/${FILE}.pl 		\
		> ${WRKSRC}/${FILE}
.endfor
.for FILE in pkgdepgraph.1 pkgdepgraph.0
	${SED} -e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'	\
		-e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'	\
		< ${WRKSRC}/${FILE}.in		\
		> ${WRKSRC}/${FILE}
.endfor
.if ${OPSYS} == "SunOS" || ${OPSYS} == "AIX"
	# the pre-generated man-pages are 'mandoc';  these OS need 'man'
	nroff -man ${WRKSRC}/pkgdepgraph.1 > ${WRKSRC}/pkgdepgraph.0
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgdepgraph ${DESTDIR}${PREFIX}/bin/pkgdepgraph
.if !empty(MANINSTALL:Mcatinstall)
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.endif
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

.include "../../mk/bsd.pkg.mk"
