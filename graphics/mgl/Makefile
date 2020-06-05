# $NetBSD: Makefile,v 1.44 2020/06/05 12:49:09 jperkin Exp $
#

DISTNAME=	mgl2-alpha-020
PKGNAME=	mgl-0.2.0a
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	http://at.sakura.ne.jp/~suz/arc/

MAINTAINER=	fk200329@fsinet.or.jp
HOMEPAGE=	https://www.NetBSD.org/ports/hpcmips/mgl2.html
COMMENT=	Graphics library for NEC Mobilegear/PocketBSD, NetBSD/hpcmips

DEPENDS+=	mglfonts>=0.1:../../fonts/mglfonts

PKG_DESTDIR_SUPPORT=	destdir

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake flex

MGLDOCS=	im.doc mgl1.doc shlib.doc
MGL2DOCS=	AppConvert.doc Build.doc CALIBRATE.doc CHANGES.doc \
		Contributors Dirs.doc HowtoUse.doc MGLAPI.doc WhatisMGL2.doc
MGL2MEMOS=	README-1st.doc TODO.txt bench.txt draw_engine.doc emsvr.doc \
		emsvrs.doc emsvrx.doc env.doc event_man.doc keymap.doc \
		files.doc mgl1.doc mgl2.doc mglbench.doc mglcol.doc \
		raw_keyboard.doc screen.doc share_fb.doc size.doc \
		structure.doc taskbar.doc
BINDOCS=	README.doc imsoft.doc
MGTERMDOCS=	bugs.doc mgterm.doc
MILDOCS=	mil.doc
NINEDOCS=	README.txt CHANGES.doc
MGLFONTUTILS=	mgl_fontcreate.c
MGLUTILS=	kill_mgl.sh mglcons.sh set_mgl.sh

ONLY_FOR_PLATFORM=	*-*-arm *-*-i386 *-*-mipsel *-*-sh3el

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	utils/mglcons.sh
SUBST_VARS.prefix=	PREFIX


SUBST_CLASSES+=		flex
SUBST_STAGE.flex=	pre-configure
SUBST_FILES.flex=	conf/config.mk-netbsd-i386-x
.if !empty(MACHINE_PLATFORM:MNetBSD-5.99*)
SUBST_SED.flex=		-e 's,@PATCH_YY_BUF_SIZE_FLAG@,,'
.else
SUBST_SED.flex=		-e 's,@PATCH_YY_BUF_SIZE_FLAG@,PATCH_YY_BUF_SIZE=y,'
.endif

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

INSTALLATION_DIRS+=	bin sbin

post-configure:
.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "mipsel" || ${MACHINE_ARCH} == "sh3el"
	${MV} -f ${WRKSRC}/conf/config.mk-hpcmips ${WRKSRC}/conf/config.mk.tmp
.else
	${MV} -f ${WRKSRC}/conf/config.mk-netbsd-i386-x ${WRKSRC}/conf/config.mk.tmp
.endif
.if ${OBJECT_FMT} == "a.out"
	${SED} -e "s/ELFENV=1/ELFENV=0/" ${WRKSRC}/conf/NetBSD.mk > ${WRKSRC}/conf/NetBSD.mk.tmp
	${MV} -f ${WRKSRC}/conf/NetBSD.mk.tmp ${WRKSRC}/conf/NetBSD.mk
	${SED} \
		-e "s@-Wl,-rpath,${PREFIX}/lib@@" \
		${WRKSRC}/conf/config.mk.tmp > ${WRKSRC}/conf/config.mk
.else
	${MV} -f ${WRKSRC}/conf/config.mk.tmp ${WRKSRC}/conf/config.mk
.endif

post-install:
.for i in ${MGLUTILS}
	${INSTALL_SCRIPT} ${WRKSRC}/utils/${i} ${DESTDIR}${PREFIX}/bin/
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/${i}
.endfor
	${LN} -s mglcons.sh ${DESTDIR}${PREFIX}/bin/start_mgl.sh

	${TEST} ! -r ${DESTDIR}${PREFIX}/bin/mglsvrcons			\
	|| ${MV} -f ${DESTDIR}${PREFIX}/bin/mglsvrcons ${DESTDIR}${PREFIX}/sbin/
	# The following three commands are only present on hpcmips:
	${TOUCH} ${DESTDIR}${PREFIX}/sbin/mglcalibrate
	${TOUCH} ${DESTDIR}${PREFIX}/sbin/calibconf
	${TOUCH} ${DESTDIR}${PREFIX}/sbin/calibdata-update
	#
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mgl2
.for i in ${MGLFONTUTILS}
	${INSTALL_DATA} ${WRKSRC}/bin/${i} ${DESTDIR}${PREFIX}/share/mgl2
.endfor
	${RM} -f -r ${DESTDIR}${PREFIX}/share/doc/mgl2
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mgl2
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mgl2/memo
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mgl2/mgterm
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mgl2/mil
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mgl2/nine
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mgl2/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mgl2/doc
.for i in ${MGLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DESTDIR}${PREFIX}/share/doc/mgl2/doc/
.endfor
.for i in ${MGL2DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/mgl2/
.endfor
.for i in ${MGL2MEMOS}
	${INSTALL_DATA} ${WRKSRC}/memo/${i} ${DESTDIR}${PREFIX}/share/doc/mgl2/memo/
.endfor
.for i in ${BINDOCS}
	${INSTALL_DATA} ${WRKSRC}/bin/${i} ${DESTDIR}${PREFIX}/share/doc/mgl2/bin/
.endfor
.for i in ${MGTERMDOCS}
	${INSTALL_DATA} ${WRKSRC}/mgterm/${i} ${DESTDIR}${PREFIX}/share/doc/mgl2/mgterm/
.endfor
.for i in ${MILDOCS}
	${INSTALL_DATA} ${WRKSRC}/mil/${i} ${DESTDIR}${PREFIX}/share/doc/mgl2/mil/
.endfor
.for i in ${NINEDOCS}
	${INSTALL_DATA} ${WRKSRC}/nine/${i} ${DESTDIR}${PREFIX}/share/doc/mgl2/nine/
.endfor

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
