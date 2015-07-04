# $NetBSD: Makefile,v 1.27 2015/07/04 16:18:30 joerg Exp $
#

DISTNAME=	xtrs-4.9d
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.tim-mann.org/trs80/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	TRS-80 Model I/III/4 Emulator for Unix

BUILD_TARGET=	default

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"

SUBST_CLASSES+=		mf
SUBST_STAGE.mf=		post-configure
SUBST_FILES.mf=		Makefile.local
SUBST_SED.mf=		-e 's|/usr/local|${PREFIX}|g'
SUBST_SED.mf+=		-e 's|/usr/X11/|${X11BASE}/|g'
SUBST_SED.mf+=		-e 's|/usr/include/X11|${X11BASE}/include|g'
SUBST_SED.mf+=		-e 's|/share/man|/${PKGMANDIR}|g'

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-configure
SUBST_FILES.oss=	trs_cassette.c cassette
.if ${OSS_TYPE} != none
SUBST_SED.oss=		-e 's|/dev/dsp|${DEVOSSSOUND}|g'
SUBST_SED.oss+=		-e 's|if __linux|if 1|'
.endif

.if ${OSS_TYPE} != none
MAKE_FLAGS+=		EXTRALIBS=${BUILDLINK_LDADD.oss}
.endif

SUBST_CLASSES+=		termcap
SUBST_STAGE.termcap=	post-configure
SUBST_FILES.termcap=	Makefile.local
.if ${TERMCAP_TYPE} == none
SUBST_SED.termcap+=	-e 's|-lncurses||'
.else
SUBST_SED.termcap+=	-e 's|-lncurses|${BUILDLINK_LDADD.termcap}|'
.endif

.include "../../mk/endian.mk"
# see ${WRKSRC}/Makefile.local
.if ${MACHINE_ENDIAN} == "big"
MAKE_FLAGS+=		ENDIAN=-Dbig_endian
.endif

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALLATION_DIRS=	bin lib/xtrs ${PKGMANDIR}/man1 share/doc/xtrs share/xtrs

pre-patch:
	${MV} -f ${WRKSRC}/cassette.sh ${WRKSRC}/cassette

post-install:
	${INSTALL_DATA} ${WRKSRC}/xtrsrom4p.hex ${DESTDIR}${PREFIX}/lib/xtrs/romimage.m4p
	${INSTALL_DATA} ${WRKSRC}/xtrsrom4p.README ${DESTDIR}${PREFIX}/share/doc/xtrs
	${INSTALL_DATA} ${WRKSRC}/utility.dsk ${DESTDIR}${PREFIX}/share/xtrs
	${INSTALL_DATA} ${WRKSRC}/cpmutil.dsk ${DESTDIR}${PREFIX}/share/xtrs
	${INSTALL_SCRIPT} ${WRKSRC}/cassette ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
