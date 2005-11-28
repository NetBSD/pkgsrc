# $NetBSD: Makefile,v 1.7 2005/11/28 06:41:20 jlam Exp $

DISTNAME=	ghostscript-cmaps-20020913
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

DEPENDS+=	adobe-cmaps>=20020913:../../fonts/adobe-cmaps

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	CMap resources for Ghostscript

GHOSTSCRIPT_REQD=	6.53

ADOBE_RESOURCEDIR=	${PREFIX}/share/Adobe/Resource
GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/Resource

EXTRACT_ONLY=		# empty
USE_TOOLS+=		gs:run
NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_PKGINSTALL=		yes

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

FILES_SUBST+=		ADOBE_RESOURCEDIR=${ADOBE_RESOURCEDIR}
FILES_SUBST+=		GS_RESOURCEDIR=${GS_RESOURCEDIR}
FILES_SUBST+=		PKG_INFO=${PKG_TOOLS_BIN}/pkg_info

REQD_DIRS=		${GS_RESOURCEDIR} ${GS_RESOURCEDIR}/CMap

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
