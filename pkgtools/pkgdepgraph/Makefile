# $NetBSD: Makefile,v 1.41 2019/08/11 13:22:36 wiz Exp $
#

PKGNAME=	pkgdepgraph-2.8
PKGREVISION=	8
CATEGORIES=	pkgtools devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Visual representation of installed NetBSD packages

# removed so that pkgdepgraph can be used on "client" machines -- @@@
# DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run

NO_CONFIGURE=	yes

DISTVER=	${PKGVERSION_NOREV}

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	${CP} ${FILESDIR}/pkgdepgraph.pl ${WRKSRC}/pkgdepgraph.pl
	${CP} ${FILESDIR}/pkgdepgraph.1 ${WRKSRC}/pkgdepgraph.1.in
	${CP} ${FILESDIR}/pkgdepgraph.0 ${WRKSRC}/pkgdepgraph.0.in

do-build:
.for file in pkgdepgraph
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'	\
		-e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'	\
		-e 's|@DISTVER@|${DISTVER}|g'		\
		-e 's|@PERL5@|${PERL5}|g'		\
		< ${WRKSRC}/${file}.pl 		\
		> ${WRKSRC}/${file}
.endfor
.for file in pkgdepgraph.1 pkgdepgraph.0
	${SED} -e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'	\
		-e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'	\
		< ${WRKSRC}/${file}.in		\
		> ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgdepgraph ${DESTDIR}${PREFIX}/bin/pkgdepgraph
.if !empty(MANINSTALL:Mcatinstall)
.  if defined(CATMAN_SECTION_SUFFIX) && !empty(CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss])
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/pkgdepgraph.1
.  else
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.  endif
.endif
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

.include "../../mk/bsd.pkg.mk"
