# $NetBSD: Makefile,v 1.8 2003/12/18 14:29:11 grant Exp $
#

DISTNAME=		pkg_filecheck-0.1
WRKSRC=			${WRKDIR}
CATEGORIES=		pkgtools devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		dillo@NetBSD.org
#HOMEPAGE=		http://www.NetBSD.org/Documentation/netbsd/Packages.txt
COMMENT=		Check for files not owned by any package

USE_PERL5=	run
USE_PKGINSTALL=	yes
USE_DB185=	yes

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

FILES_SUBST+=	X11PREFIX=${X11PREFIX}
CONF_FILES=	${PREFIX}/share/examples/pkg_filecheck/pkg_filecheck.conf \
		${PKG_SYSCONFDIR}/pkg_filecheck.conf

do-build:
.for f in builddb.pl builddb.1 pkg_filecheck.conf pkg_filecheck.conf.5 \
	pkg_filecheck.c pkg_filecheck.1
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/${f} > ${WRKSRC}/${f}
.endfor
	cd ${WRKSRC} \
	    && ${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} \
		-o pkg_filecheck pkg_filecheck.c \
		${BUILDLINK_LDFLAGS.db} ${BUILDLINK_LIBS.db}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/builddb.pl ${PREFIX}/bin/builddb
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_filecheck ${PREFIX}/bin/pkg_filecheck
	${INSTALL_MAN} ${WRKSRC}/builddb.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkg_filecheck.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkg_filecheck.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pkg_filecheck
	${INSTALL_DATA} ${WRKSRC}/pkg_filecheck.conf \
		${PREFIX}/share/examples/pkg_filecheck/pkg_filecheck.conf

.include "../../databases/db/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
