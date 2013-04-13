# $NetBSD: Makefile,v 1.11 2013/04/13 12:01:42 ryoon Exp $
#

DISTNAME=	liberation-fonts-ttf-2.00.1
PKGNAME=	${DISTNAME:S/-fonts//}
CATEGORIES=	fonts
MASTER_SITES=	https://fedorahosted.org/releases/l/i/liberation-fonts/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.redhat.com/promo/fonts/
COMMENT=	TrueType fonts from RedHat
LICENSE=	ofl-v1.1

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

NO_BUILD=	yes
NO_CONFIGURE=	yes

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${DOCDIR} ${FONTDIR}

do-install:
	set -e; \
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f ; \
	done

	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/ChangeLog \
		${WRKSRC}/LICENSE ${WRKSRC}/README ${WRKSRC}/TODO \
		${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
