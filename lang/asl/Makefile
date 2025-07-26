# $NetBSD: Makefile,v 1.1 2025/07/26 03:06:53 tsutsui Exp $

DISTNAME=	asl-current-142-bld291
PKGNAME=	${DISTNAME:S/-current//:S/-bld/./}
CATEGORIES=	devel
MASTER_SITES=	http://john.ccac.rwth-aachen.de:8000/ftp/as/source/c_version/

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://john.ccac.rwth-aachen.de:8000/as/
COMMENT=	Portable macro cross assembler for various microprocessors
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c

# to generate .doc and .html manuals
TOOL_DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin

WRKSRC=			${WRKDIR}/asl-current

SUBST_CLASSES+=		def
SUBST_MESSAGE.def=	Set proper environments in Makefile.def.
SUBST_STAGE.def=	post-configure
SUBST_FILES.def=	Makefile.def
SUBST_VARS.def=		CC CFLAGS LD LDFLAGS

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/asl share/doc/asl

do-configure:
	${CP} ${FILESDIR}/Makefile.def ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
