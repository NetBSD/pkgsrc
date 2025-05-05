# $NetBSD: Makefile,v 1.1 2025/05/05 16:51:58 vins Exp $

DISTNAME=	dina-2.93
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.osuosl.org/pub/gentoo/distfiles/fe/
EXTRACT_SUFX=	.zip

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://www.donationcoder.com/Software/Jibz/Dina/index.html
COMMENT=	Monospace bitmap font, primarily aimed at programmers
LICENSE=	mit

WRKSRC=		${WRKDIR}/BDF

USE_LANGUAGES=	# none
USE_TOOLS+=	bdftopcf gzip

NO_CONFIGURE=	yes

FONTDIR=		share/fonts/X11/PCF

REQD_DIRS=		${FONTDIR}
FONTS_DIRS.x11=		${FONTDIR}
INSTALLATION_DIRS=	${FONTDIR}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-extract
SUBST_MESSAGE.prefix=	Setting standard Latin-1 encoding.
SUBST_FILES.prefix=	*.bdf
SUBST_SED.prefix+=	-e "s/microsoft-cp1252/ISO8859-1/"

do-build:
	${RUN}cd ${WRKSRC} && \
	for i in *.bdf; do \
	bdftopcf -t $$i | ${GZIP_CMD} -c > $$i.pcf.gz; \
	done

do-install:
	${RUN}for i in *.pcf.gz; do \
	${INSTALL_DATA} ${WRKSRC}/$$i \
		${DESTDIR}${PREFIX}/${FONTDIR};	\
	done


.include "../../mk/bsd.pkg.mk"
