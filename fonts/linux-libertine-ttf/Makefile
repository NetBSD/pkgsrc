# $NetBSD: Makefile,v 1.1.1.1 2006/08/06 14:32:18 wiz Exp $
#

DISTNAME=	LinLibertineTTF-2.1.0
PKGNAME=	${DISTNAME:S/LinLibertineTTF/linux-libertine-ttf/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linuxlibertine/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linuxlibertine.sourceforge.net/
COMMENT=	Free TrueType font family

WRKSRC=		${WRKDIR}/LinLibertineTTF
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/linux-libertine-ttf
FONTS_DIRS.ttf=	${FONTDIR}

do-install:
	${INSTALL_DATA_DIR} ${FONTDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/Readme ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/gpl.txt ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
