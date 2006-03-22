# $NetBSD: Makefile,v 1.17 2006/03/22 16:56:50 minskim Exp $
#

NAME=		textpos
DISTNAME=	${NAME}
PKGNAME=	tex-${NAME}-1.2b
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/supported/${NAME}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=
COMMENT=	Absolute positioning of text on the LaTeX page

WRKSRC=		${WRKDIR}/${NAME}
DIST_SUBDIR=	${NAME}
DISTFILES=	textpos.ins LICENCE README textpos.dtx VERSION

# included in teTeX3
TEX_ACCEPTED=	teTeX1 teTeX2
CONFLICTS+=	teTeX-bin>=3.0

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

.if ${TEX_DEFAULT} == "teTeX3"
PKG_SKIP_REASON+=	"textpos is included in ${TEX_DEFAULT}."
.else
.include "../../mk/tex.buildlink3.mk"
.endif

do-extract:

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/textpos
	for f in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$f \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/textpos; \
	done

post-install:
	cd ${PKG_LOCALTEXMFPREFIX}/tex/latex/textpos; latex textpos.ins
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/bsd.pkg.mk"
