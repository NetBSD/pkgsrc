# $NetBSD: Makefile,v 1.21 2014/01/09 02:39:42 mef Exp $

DISTNAME=	ghostscript-cidfonts-20000901
PKGREVISION=	5
CATEGORIES=	fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CIDFont resources for Ghostscript

DEPENDS+=	adobe-cidfonts>=20000901:../../fonts/adobe-cidfonts
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript

GHOSTSCRIPT_REQD=	9.05

ADOBE_RESOURCEDIR=	${PREFIX}/share/Adobe/Resource
GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/${GS_VERSION}/Resource

NO_CONFIGURE=		yes
NO_BUILD=		yes

FILES_SUBST+=		ADOBE_RESOURCEDIR=${ADOBE_RESOURCEDIR:Q}
FILES_SUBST+=		GS_RESOURCEDIR=${GS_RESOURCEDIR:Q}
FILES_SUBST+=		PKG_INFO=${PKG_INFO:Q}

REQD_DIRS=		${GS_RESOURCEDIR} ${GS_RESOURCEDIR}/CIDFont

.if   !empty(PKG_OPTIONS.gs_type:Mghostscript-agpl)
. include       "../../print/ghostscript-agpl/Makefile.common"
.else
. include       "../../print/ghostscript-gpl/Makefile.common"
.endif

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
