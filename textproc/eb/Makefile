# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 11:18:27 agc Exp $
# FreeBSD Id: ports/japanese/eb/Makefile,v 1.21 2000/08/21 03:39:42 kevlo Exp

DISTNAME=	eb-2.3.8
CATEGORIES=	textproc japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/appendix/ \
		ftp://ftp.sra.co.jp/pub/misc/eb/
DISTFILES=	${EBFILES} \
		${LISTFILES} \
		${APPENDIXFILES}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}+.diff

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/eb/
COMMENT=	C library for accessing EB, EBG, EBXA and EPWING CD-ROM dictionaries

EBFILES=	${DISTNAME}${EXTRACT_SUFX}
LISTFILES=	LIST \
		LIST-ja
APPENDIXFILES=	cencro-1.0.tar.gz \
		chujiten-2.3.tar.gz \
		chujiten2-2.0.tar.gz \
		chujiten6-2.3.tar.gz \
		colloc-2.0.tar.gz \
		crownfj-2.0.tar.gz \
		daihyakka-1.0.tar.gz \
		daijirin-2.0.tar.gz \
		dd75-2.0.tar.gz \
		genius-1.0.tar.gz \
		global-2.0.tar.gz \
		heritage-2.2.tar.gz \
		izumi-2.0.tar.gz \
		jitenban-2.4.tar.gz \
		jitenban97-2.1.tar.gz \
		kanjigen-2.0.tar.gz \
		kanjigen2-2.0.tar.gz \
		kojien-2.3.tar.gz \
		kojien2-2.0.tar.gz \
		kojien4-2.2.tar.gz \
		oxford-2.0.tar.gz \
		plus-2.0.tar.gz \
		readers-2.2.tar.gz \
		readers2-2.0.tar.gz \
		superdic98-1.0.tar.gz
EXTRACT_ONLY=	${EBFILES}

DIST_SUBDIR=		eb
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-zlib
USE_GMAKE=		yes

APPENDIXDIR=	${PREFIX}/share/eb/appendix

post-extract:
	cd ${WRKSRC} && ${RM} -rf zlib

post-install:
	for f in ${LISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$f ${APPENDIXDIR}; \
	done
	for f in ${APPENDIXFILES}; do \
		${GTAR} -C ${APPENDIXDIR} -zxmf ${DISTDIR}/${DIST_SUBDIR}/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
