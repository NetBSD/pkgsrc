# $NetBSD: Makefile,v 1.9 2005/12/05 20:50:14 rillig Exp $
#

DISTNAME=	xfntmizi-1.1-2.noarch
PKGNAME=	ko-mizi-20010718
CATEGORIES=	fonts x11 korean
MASTER_SITES+=	ftp://ftp.mizi.co.kr/pub/hanIM/
EXTRACT_SUFX=	.rpm

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	X11 fonts for KSC 5601 standard

BUILD_DEPENDS+=	rpm-[0-9]*:../../misc/rpm

CONFLICTS+=	ksc5601fonts-[0-9]*

USE_X11BASE=		yes
USE_TOOLS+=		gzip gunzip mkfontdir:run

MAKE_ENV+=	FONTDIR=${FONTDIR:Q} GZIP_CMD=${GZIP_CMD:Q}

# fonts
MIZI_PCF=	mzgt16e.pcf mzgt16h1.pcf mzmj16h.pcf mzpg16h.pcf mzsm16h.pcf \
		mzgt16h.pcf mzmj16e.pcf mzpg16e.pcf mzsm16e.pcf

FONTDIR=${PREFIX}/lib/X11/fonts/local

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${.CURDIR}/../../fonts/ko-x11fonts/files/Makefile ${WRKSRC}
	(cd ${WRKSRC}; rpm2cpio ${_DISTDIR}/${DISTFILES} | \
	    cpio -i --make-directories *.pcf.Z)
	(cd ${WRKSRC}; for i in ${MIZI_PCF}; do \
		${GUNZIP_CMD} -c usr/lib/X11/fonts/misc/$$i.Z > $$i; \
	done)
	(cd ${WRKSRC}; ${MAKE} prepare)

pre-install:
	[ -d ${FONTDIR} ] || ${INSTALL_DATA_DIR} ${FONTDIR}

post-install:
	(cd ${FONTDIR}; mkfontdir)

.include "../../mk/bsd.pkg.mk"
