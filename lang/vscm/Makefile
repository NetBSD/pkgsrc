# $NetBSD: Makefile,v 1.1.1.1 2000/11/02 11:01:53 itojun Exp $

DISTNAME=	vscmV0r4
PKGNAME=	vscm-0.4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/vscm/

PATCHFILES=	bugfix.txt
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	packages@netbsd.org

USE_GMAKE=	yes

post-patch:
	${SED} -e "s,@PREFIX@,${PREFIX}," <${FILESDIR}/path.h >${WRKSRC}/path.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scheme ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/vscm
	${INSTALL_DATA} ${WRKSRC}/.scheme-boot ${PREFIX}/lib/vscm/scheme-boot
	${MKDIR} ${PREFIX}/share/examples/vscm
	for i in README INSTALL DESCRIPTION; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/examples/vscm; \
	done

.include "../../mk/bsd.pkg.mk"
