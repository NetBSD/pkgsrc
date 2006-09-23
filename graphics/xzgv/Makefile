# $NetBSD: Makefile,v 1.35 2006/09/23 14:59:34 adrianp Exp $

DISTNAME=	xzgv-0.8
PKGNAME=	xzgv-0.8.0.1
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/apps/graphics/viewers/X/

PATCHFILES=	xzgv-0.8-integer-overflow-fix.diff
PATCH_SITES=	http://rus.members.beeb.net/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/xzgv.html
COMMENT=	Image viewer

USE_X11BASE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		# PLIST
INSTALLATION_DIRS=	bin ${PKGINFODIR} ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${PREFIX}/${PKGMANDIR}/man1
	@(cd ${WRKSRC}/doc && ${MAKEINFO} xzgv.texi)
	cd ${WRKSRC}/doc; for f in xzgv xzgv-[0-9]*; do			\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
