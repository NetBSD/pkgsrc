# $NetBSD: Makefile,v 1.1.1.1 2014/04/27 00:10:34 agc Exp $

DISTNAME=		genpkgng-20140425
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Convert a pkgsrc binary package to a FreeBSD pkg
LICENSE=		modified-bsd

AUTO_MKDIRS=		yes

SUBST_CLASSES+=		mtree
SUBST_STAGE.mtree=	pre-configure
SUBST_MESSAGE.mtree=	Fix location of MTREE_DIRS file
SUBST_FILES.mtree=	genpkgng.sh
SUBST_SED.mtree=	-e 's|@MTREE_DIR_DIR@|${PREFIX}/libdata/genpkgng|'

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/genpkgng ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/MTREE_DIRS ${DESTDIR}${PREFIX}/libdata/genpkgng/
	${INSTALL_MAN} ${WRKSRC}/genpkgng.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
