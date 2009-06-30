# $NetBSD: Makefile,v 1.17 2009/06/30 00:07:18 joerg Exp $

DISTNAME=	vscmV0r4
PKGNAME=	vscm-0.4
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/vscm/

PATCHFILES=	bugfix.txt
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.princeton.edu/~blume/vscm/
COMMENT=	Portable scheme implementation

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

post-patch:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/path.h >${WRKSRC}/path.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vscm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/vscm
	${INSTALL_DATA} ${WRKSRC}/.scheme-boot				\
		${DESTDIR}${PREFIX}/lib/vscm/vscm-boot
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vscm
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL DESCRIPTION	\
		${DESTDIR}${PREFIX}/share/doc/vscm

.include "../../mk/bsd.pkg.mk"
