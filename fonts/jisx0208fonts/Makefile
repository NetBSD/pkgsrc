# $NetBSD: Makefile,v 1.17 2001/04/30 04:16:09 jlam Exp $
#

DISTNAME=	jisx0208fonts-20010112
CATEGORIES=	fonts x11 japanese
MASTER_SITES=   ftp://ftp.iij.ad.jp/pub/X/X11R6.4/xc/fonts/bdf/misc/ \
		ftp://ftp.eu.net/X11/R6.4/xc/fonts/bdf/misc/
DISTFILES=	${ELISA10X8} ${ELISA8X8} ${KANAME12} ${KAPPA20} ${NAGA10} \
		${K12X10} ${SHINONOME12}

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	X11 fonts for JIS X0208 standard

# not USE_GMAKE
BUILD_DEPENDS+=	gmake-3.79.1:../../devel/gmake

.include "../../mk/bsd.prefs.mk"
USE_NON_SQUARE?= NO
USE_SHINONOME?=	YES
USE_KANAME?=	YES

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty

MAKE_ENV+=	FONTDIR=${FONTDIR} GZIP_CMD="${GZIP_CMD}"
FONTDIR=${PREFIX}/lib/X11/fonts/local

.if ${USE_NON_SQUARE} == YES
MASTER_SITES+=	http://hp.vector.co.jp/authors/VA004814/freesoft/ \
		ftp://ftp.jp.netbsd.org/pub/NetBSD-jp/tut-jp/fonts/
ELISA10X8=	elisau10.tgz clR5x8.bdf
EXTRACT_ONLY+=	elisau10.tgz
PLIST_SRC+=	${PKGDIR}/PLIST.elisau
.endif

MASTER_SITES+=	http://www.tea.forus.or.jp/toshi/exhibition/
ELISA8X8=	elisat10.tar.gz
EXTRACT_ONLY+=	elisat10.tar.gz
PLIST_SRC+=	${PKGDIR}/PLIST.elisat

.if ${USE_KANAME} == YES
MASTER_SITES+=	http://www.din.or.jp/~storm/fonts/
KANAME12=	kaname_k12_bdf.tar.gz
EXTRACT_ONLY+=	kaname_k12_bdf.tar.gz
PLIST_SRC+=	${PKGDIR}/PLIST.kaname
.endif

.if ${USE_SHINONOME} == YES
MASTER_SITES+=	http://www.on.ics.keio.ac.jp/~yasu/linux/fonts/
SHINONOME12=	shinonome12-1.0.8.tar.bz2
EXTRACT_ONLY+=	shinonome12-1.0.8.tar.bz2
PLIST_SRC+=	${PKGDIR}/PLIST.shinonome

SHINONOME_CONFIGURE_ENV=${CONFIGURE_ENV} PERL="${PERL5}"
SHINONOME_CONFIGURE_ARGS=${CONFIGURE_ARGS} --with-fontdir=${FONTDIR} --disable-progressbar

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5
.endif

MASTER_SITES+=	ftp://ftp.jaist.ac.jp/pub/misc/character/fonts/kappa/
KAPPA20=	Kappa20-0.3.tar.gz
EXTRACT_ONLY+=	Kappa20-0.3.tar.gz
PLIST_SRC+=	${PKGDIR}/PLIST.kappa

MASTER_SITES+=	http://hp.vector.co.jp/authors/VA013391/fonts/
NAGA10=		knj10-1.1.tar.gz 6x12.tar.gz
EXTRACT_ONLY+=	knj10-1.1.tar.gz 6x12.tar.gz
PLIST_SRC+=	${PKGDIR}/PLIST.naga10

.if ${USE_NON_SQUARE} == YES
MASTER_SITES+=	http://www.softclub.co.jp/~zoro/k12x10/
K12X10=		k12x10bdf.tar.gz
EXTRACT_ONLY+=	k12x10bdf.tar.gz
PLIST_SRC+=	${PKGDIR}/PLIST.k12x10
.endif

PLIST_SRC+=	${PKGDIR}/PLIST.end

post-extract:
	${MKDIR} ${WRKSRC}
.if ${USE_NON_SQUARE} == YES
	${CP} ${DISTDIR}/clR5x8.bdf ${WRKDIR}
.endif
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
.if ${USE_SHINONOME} == YES
	@(cd ${WRKDIR}/shinonome12-1.0.8 ; \
	${SETENV} ${SHINONOME_CONFIGURE_ENV} ${CONFIGURE_SCRIPT} \
		${SHINONOME_CONFIGURE_ARGS} ; \
	${SETENV} ${MAKE_ENV} gmake bdf; \
	${RM} hankaku/*.bdf latin1/*.bdf)
.endif
	(cd ${WRKSRC}; ${MAKE} prepare)

# for do-patch
.if ${USE_KANAME} != YES
NO_PATCH=	YES
.endif

pre-install:
	[ -d ${FONTDIR} ] || ${INSTALL_DATA_DIR} ${FONTDIR}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jisx0208fonts
	${INSTALL_DATA} ${WRKDIR}/knj10-1.1/README \
		${PREFIX}/share/doc/jisx0208fonts/README.naga10-1.1
	${INSTALL_DATA} ${FILESDIR}/README.kappa20 \
		${PREFIX}/share/doc/jisx0208fonts
	(cd ${FONTDIR}; mkfontdir)

.include "../../mk/bsd.pkg.mk"
