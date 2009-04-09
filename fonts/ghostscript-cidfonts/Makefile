# $NetBSD: Makefile,v 1.15 2009/04/09 00:48:08 joerg Exp $

DISTNAME=	ghostscript-cidfonts-20000901
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CIDFont resources for Ghostscript

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	adobe-cidfonts>=20000901:../../fonts/adobe-cidfonts

GHOSTSCRIPT_REQD=	6.53

ADOBE_RESOURCEDIR=	${PREFIX}/share/Adobe/Resource
GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/Resource

NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_TOOLS+=		gs:run

FILES_SUBST+=		ADOBE_RESOURCEDIR=${ADOBE_RESOURCEDIR:Q}
FILES_SUBST+=		GS_RESOURCEDIR=${GS_RESOURCEDIR:Q}
FILES_SUBST+=		PKG_INFO=${PKG_INFO:Q}

REQD_DIRS=		${GS_RESOURCEDIR} ${GS_RESOURCEDIR}/CIDFont

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
