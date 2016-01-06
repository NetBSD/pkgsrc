# $NetBSD: Makefile,v 1.17 2016/01/06 10:46:53 adam Exp $

DISTNAME=	tesseract-ocr-3.02.02
PKGNAME=	${DISTNAME:S/-ocr//}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://tesseract-ocr.googlecode.com/files/
DISTFILES+=	${DISTNAME}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/tesseract-ocr/
COMMENT=	Commercial quality open source OCR engine
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pax
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LIBLEPT_HEADERSDIR=${BUILDLINK_PREFIX.leptonica}/include
MAKE_ENV+=		LANGS=${TESSERACT_LANGS:Q}

WRKSRC=			${WRKDIR}/tesseract-ocr

INSTALLATION_DIRS=	libexec share/doc/tesseract share/tesseract

TESSERACT_LANGS=	afr ara aze bel ben bul cat ces chi_sim chi_tra chr \
			dan deu ell eng enm epo equ est eus fin fra frk frm \
			glg grc heb hin hrv hun ind isl ita jpn kan kor lav \
			lit mal mkd mlt msa nld nor pol por rus slk slv spa \
			sqi srp swa swe tam tel tgl tha tur ukr vie
.for l in ${TESSERACT_LANGS}
DISTFILES+=	tesseract-ocr-3.02.${l}.tar.gz
.endfor

LIBS.SunOS+=		-lsocket -lnsl

.include "../../graphics/leptonica/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
