# $NetBSD: Makefile,v 1.1.1.1 2003/07/13 16:15:34 wiz Exp $
#

DISTNAME=		pkg_filecheck-0.1
WRKSRC=			${WRKDIR}
CATEGORIES=		pkgtools devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		dillo@netbsd.org
#HOMEPAGE=		http://www.netbsd.org/Documentation/netbsd/Packages.txt
COMMENT=		check for files not owned by any package

USE_PERL5=	run

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

CONF_FILES=	${PREFIX}/share/examples/pkg_filecheck/pkg_filecheck.conf \
		${PKG_SYSCONFDIR}/pkg_filecheck.conf

do-build:
.for f in builddb.pl builddb.1 pkg_filecheck.conf pkg_filecheck.conf.5 \
	pkg_filecheck.c pkg_filecheck.1
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g' \
		-e 's|@X11PREFIX@|${X11PREFIX}|g' \
		< ${FILESDIR}/${f} \
		> ${WRKSRC}/${f}
.endfor
	cd ${WRKSRC} && ${MAKE} pkg_filecheck

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/builddb.pl ${PREFIX}/bin/builddb
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_filecheck ${PREFIX}/bin/pkg_filecheck
	${INSTALL_MAN} ${WRKSRC}/builddb.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkg_filecheck.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkg_filecheck.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pkg_filecheck
	${INSTALL_DATA} ${WRKSRC}/pkg_filecheck.conf \
		${PREFIX}/share/examples/pkg_filecheck/pkg_filecheck.conf

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
