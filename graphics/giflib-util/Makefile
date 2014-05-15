# $NetBSD: Makefile,v 1.8 2014/05/15 14:16:11 adam Exp $

.include "../../graphics/giflib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-util-/}

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

.include "../../mk/giflib.buildlink3.mk"
.if ${GIFLIB_IMPLEMENTATION} == "libungif"
PKG_FAIL_REASON= "please use graphics/libungif"
.endif
.include "../../mk/bsd.pkg.mk"
