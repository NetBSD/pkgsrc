# $NetBSD: Makefile,v 1.2 2008/03/03 20:17:12 jlam Exp $
#

DISTNAME=	LinLibertineTTF-2.1.0
PKGNAME=	${DISTNAME:S/LinLibertineTTF/linux-libertine-ttf/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linuxlibertine/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linuxlibertine.sourceforge.net/
COMMENT=	Free TrueType font family

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/LinLibertineTTF
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/linux-libertine-ttf
FONTS_DIRS.ttf=	${FONTDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/Readme ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/gpl.txt ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
