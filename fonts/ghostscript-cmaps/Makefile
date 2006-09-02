# $NetBSD: Makefile,v 1.14 2006/09/02 20:37:00 rillig Exp $

DISTNAME=	ghostscript-cmaps-20020913
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

DEPENDS+=	adobe-cmaps>=20020913:../../fonts/adobe-cmaps

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CMap resources for Ghostscript

GHOSTSCRIPT_REQD=	6.53

ADOBE_RESOURCEDIR=	${PREFIX}/share/Adobe/Resource
GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/Resource

EXTRACT_ONLY=		# empty
USE_TOOLS+=		gs:run
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

FILES_SUBST+=		ADOBE_RESOURCEDIR=${ADOBE_RESOURCEDIR:Q}
FILES_SUBST+=		GS_RESOURCEDIR=${GS_RESOURCEDIR:Q}
FILES_SUBST+=		PKG_INFO=${PKG_INFO:Q}

REQD_DIRS=		${GS_RESOURCEDIR} ${GS_RESOURCEDIR}/CMap

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
