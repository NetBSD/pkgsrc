# $NetBSD: Makefile,v 1.19 2005/12/05 20:50:51 rillig Exp $
#

DISTNAME=		pkg_filecheck-0.1
PKGREVISION=		1
CATEGORIES=		pkgtools devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		dillo@NetBSD.org
#HOMEPAGE=		http://www.NetBSD.org/Documentation/netbsd/doc/pkgsrc.html
COMMENT=		Check for files not owned by any package

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run
USE_PKGINSTALL=	yes

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

FILES_SUBST+=	X11PREFIX=${X11PREFIX:Q}
FILES_SUBST+=	PKG_DBDIR=${PKG_DBDIR:Q}
CONF_FILES=	${PREFIX}/share/examples/pkg_filecheck/pkg_filecheck.conf \
		${PKG_SYSCONFDIR}/pkg_filecheck.conf

INSTALLATION_DIRS=	bin man/man1 man/man5

.include "../../mk/bdb.buildlink3.mk"

do-build:
.for f in builddb.pl builddb.1 pkg_filecheck.conf pkg_filecheck.conf.5 \
	pkg_filecheck.c pkg_filecheck.1
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/${f} > ${WRKSRC}/${f}
.endfor
	cd ${WRKSRC} \
	    && ${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${BDB_LIBS} \
		-o pkg_filecheck pkg_filecheck.c \

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/builddb.pl ${PREFIX}/bin/builddb
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_filecheck ${PREFIX}/bin/pkg_filecheck
	${INSTALL_MAN} ${WRKSRC}/builddb.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkg_filecheck.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkg_filecheck.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pkg_filecheck
	${INSTALL_DATA} ${WRKSRC}/pkg_filecheck.conf \
		${PREFIX}/share/examples/pkg_filecheck/pkg_filecheck.conf

.include "../../pkgtools/libnbcompat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
