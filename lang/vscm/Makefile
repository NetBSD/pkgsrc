# $NetBSD: Makefile,v 1.6 2001/04/12 20:21:59 jtb Exp $

DISTNAME=	vscmV0r4
PKGNAME=	vscm-0.4nb1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/vscm/

PATCHFILES=	bugfix.txt
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.princeton.edu/~blume/vscm/
COMMENT=	Portable scheme implementation

USE_GMAKE=	yes

post-patch:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/path.h >${WRKSRC}/path.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vscm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/vscm
	${INSTALL_DATA} ${WRKSRC}/.scheme-boot ${PREFIX}/lib/vscm/vscm-boot
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vscm
	for i in README INSTALL DESCRIPTION; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/examples/vscm; \
	done

.include "../../mk/bsd.pkg.mk"
