# $NetBSD: Makefile,v 1.19 2005/05/07 22:24:04 wiz Exp $
#

DISTNAME=	pkgdepgraph-2.7
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	atatat@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Visual representation of installed NetBSD packages

# removed so that pkgdepgraph can be used on "client" machines -- @@@
# DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

WRKSRC=		${WRKDIR}
USE_PERL5=	YES

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

DISTVER=	${DISTNAME:S/pkgdepgraph-//}

.include "../../mk/bsd.prefs.mk"

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
	${INSTALL_SCRIPT} ${WRKSRC}/pkgdepgraph ${PREFIX}/bin/pkgdepgraph
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${WRKSRC}/pkgdepgraph.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
