# $NetBSD: Makefile,v 1.5 2011/10/22 08:50:18 ryoon Exp $
#

DISTNAME=	liberation-fonts-ttf-1.07.1
PKGNAME=	${DISTNAME:S/-fonts//}
CATEGORIES=	fonts
MASTER_SITES=	https://fedorahosted.org/releases/l/i/liberation-fonts/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.redhat.com/promo/fonts/
COMMENT=	TrueType fonts from RedHat
LICENSE=	gnu-gpl-v2 # with some exception

FETCH_USING=	curl

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
NO_CONFIGURE=	yes

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIR.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${DOCDIR} ${FONTDIR}

do-install:
	set -e; \
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f ; \
	done

	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/License.txt \
		${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
