# $NetBSD: Makefile,v 1.45 2011/01/13 13:38:24 wiz Exp $
#

DISTNAME=	xzgv-0.9.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xzgv/}

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/xzgv
COMMENT=	Image viewer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=		yes
USE_TOOLS+=		gmake makeinfo pkg-config gawk
INFO_FILES=		yes
INSTALLATION_DIRS=	bin ${PKGINFODIR} ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	@(cd ${WRKSRC}/doc && ${MAKEINFO} xzgv.texi)
	cd ${WRKSRC}/doc; for f in xzgv.info; do			\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
