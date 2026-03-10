# $NetBSD: Makefile,v 1.17 2026/03/10 20:40:57 wiz Exp $

.include "../../graphics/giflib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-util-/}

COMMENT=	GIF image format utility

CONFLICTS+=	libungif-[0-9]*

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

INSTALL_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}

HTMLDIR=		share/doc/giflib
INSTALLATION_DIRS=	${HTMLDIR} ${HTMLDIR}/gifstandard \
			${HTMLDIR}/whatsinagif \
			${PKGMANDIR}/man1

INSTALL_TARGET= 	install-bin
post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html \
		${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}/doc/gifstandard && ${INSTALL_DATA} *.txt \
		${DESTDIR}${PREFIX}/${HTMLDIR}/gifstandard
	cd ${WRKSRC}/doc/whatsinagif && ${INSTALL_DATA} *.html *.gif \
		${DESTDIR}${PREFIX}/${HTMLDIR}/whatsinagif

.include "../../graphics/giflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
