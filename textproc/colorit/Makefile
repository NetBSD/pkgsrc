# $NetBSD: Makefile,v 1.1.1.1 2012/05/12 15:15:35 cheusov Exp $

.include "../../textproc/dict-server/Makefile.common"

PKGNAME=	${DISTNAME:S/dictd/colorit/}
CATEGORIES=	textproc
COMMENT=	Utility for coloring output

LICENSE=		public-domain

USE_TOOLS+=		gawk:run

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${EGDIR} ${EGDIR}/.colorit.d

EGDIR=			${PREFIX}/share/examples/colorit

DISTINFO_FILE=	${.CURDIR}/../../textproc/dict-server/distinfo
PATCHDIR=	${.CURDIR}/../../textproc/dict-server/patches

do-build:
	set -e; cd ${WRKSRC}; \
	sed 's|@sysconfdir@|${PKG_SYSCONFDIR}|' colorit.in > colorit; \
	sed 's|@SYSCONFDIR@|${PKG_SYSCONFDIR}|' colorit.1.in > colorit.1; \
	chmod +x colorit

do-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_SCRIPT} colorit ${DESTDIR}${PREFIX}/bin; \
	${INSTALL_MAN} colorit.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	cp ${.CURDIR}/files/colorit_* ${DESTDIR}${EGDIR}/; \
	cp -R ${.CURDIR}/files/.colorit.d ${DESTDIR}${EGDIR}/

.include "../../mk/bsd.pkg.mk"
