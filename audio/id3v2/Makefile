# $NetBSD: Makefile,v 1.23 2010/04/26 01:54:26 schnoebe Exp $

DISTNAME=	id3v2-0.1.12
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3v2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://id3v2.sourceforge.net/
COMMENT=	Command line editor for id3v2 tags

LICENSE=	gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-configure:
	# clean up inappropriate stuff left in the distribution archive
	cd ${WRKSRC}; rm -f id3v2 *.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/id3v2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/id3v2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/id3v2
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/id3v2/README

.include "../../converters/libiconv/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
