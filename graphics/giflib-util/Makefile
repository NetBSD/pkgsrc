# $NetBSD: Makefile,v 1.9 2014/05/31 15:56:27 wiz Exp $

.include "../../graphics/giflib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-util-/}
PKGREVISION=	1

COMMENT=	GIF image format utility

CONFLICTS+=	libungif-[0-9]*

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

BUILD_DIRS+=		util doc
HTMLDIR=		share/doc/giflib
INSTALLATION_DIRS=	${HTMLDIR} ${HTMLDIR}/whatsinagif

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.txt \
		${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${WRKSRC}/doc/whatsinagif && ${INSTALL_DATA} *.html *.gif \
		${DESTDIR}${PREFIX}/${HTMLDIR}/whatsinagif

.include "../../graphics/giflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
