# $NetBSD: Makefile,v 1.5 2005/05/15 22:02:27 jlam Exp $

DISTNAME=	efont-unicode-bdf-0.4.2
PKGNAME=	${DISTNAME:S/-bdf//}
CATEGORIES=	fonts x11
MASTER_SITES=	http://openlab.ring.gr.jp/efont/dist/unicode-bdf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/efont/unicode/
COMMENT=	Free unicode BDF font

USE_X11BASE=		YES
PKGSRC_USE_TOOLS+=	gzip

MESSAGE_SUBST+=	FONTDIR=${FONTDIR}
PLIST_SUBST+=	FONTDIR=${FONTDIR}

FONTS=		b10 b10_b b10_bi b10_i\
		b12 b12_b b12_bi b12_i\
		b14 b14_b b14_bi b14_i\
		b16 b16_b b16_bi b16_i\
		b24 b24_b b24_bi b24_i\
		h10 h10_b h10_bi h10_i\
		h12 h12_b h12_bi h12_i\
		h14 h14_b h14_bi h14_i\
		h16 h16_b h16_bi h16_i\
		h24 h24_b h24_bi h24_i
FONTDIR=	lib/X11/fonts/efont

do-build:
	@cd ${WRKSRC};						\
	for FONT in ${FONTS}; do				\
	  ${ECHO} -n "Compiling font $${FONT} ... ";		\
	  ${X11BASE}/bin/bdftopcf $${FONT}.bdf |		\
	    ${GZIP_CMD} -c >$${FONT}.pcf.gz;			\
	  ${ECHO} "done";					\
	done

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/${FONTDIR}
	@for FONT in ${FONTS}; do				\
	  ${ECHO} -n "Installing font $${FONT} ... ";		\
	  ${INSTALL_DATA} ${WRKSRC}/$${FONT}.pcf.gz 		\
	    ${PREFIX}/${FONTDIR};				\
	  ${ECHO} "done";					\
	done
	@cd ${PREFIX}/${FONTDIR}; ${X11BASE}/bin/mkfontdir

.include "../../mk/bsd.pkg.mk"
