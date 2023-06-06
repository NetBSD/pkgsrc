# $NetBSD: Makefile,v 1.13 2023/06/06 12:41:31 riastradh Exp $

PKGREVISION= 1
.include "../../graphics/giflib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-util-/}

COMMENT=	GIF image format utility

CONFLICTS+=	libungif-[0-9]*

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

HTMLDIR=		share/doc/giflib
INSTALLATION_DIRS=	${HTMLDIR} ${HTMLDIR}/gifstandard \
			${HTMLDIR}/whatsinagif

INSTALL_TARGET= 	install-bin
INSTALL_TARGET+= 	install-man
post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html \
		${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${WRKSRC}/doc/gifstandard && ${INSTALL_DATA} *.txt \
		${DESTDIR}${PREFIX}/${HTMLDIR}/gifstandard
	cd ${WRKSRC}/doc/whatsinagif && ${INSTALL_DATA} *.html *.gif \
		${DESTDIR}${PREFIX}/${HTMLDIR}/whatsinagif

.include "../../graphics/giflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
