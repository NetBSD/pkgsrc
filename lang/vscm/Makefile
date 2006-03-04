# $NetBSD: Makefile,v 1.15 2006/03/04 21:29:57 jlam Exp $

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

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

post-patch:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/path.h >${WRKSRC}/path.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vscm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/vscm
	${INSTALL_DATA} ${WRKSRC}/.scheme-boot ${PREFIX}/lib/vscm/vscm-boot
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vscm
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL DESCRIPTION	\
			${PREFIX}/share/doc/vscm

.include "../../mk/bsd.pkg.mk"
