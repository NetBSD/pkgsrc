# $NetBSD: Makefile,v 1.16 2004/04/24 00:46:15 wiz Exp $
#

DISTNAME=       mgl2-alpha-020
PKGNAME=        mgl-0.2.0a
PKGREVISION=	1
CATEGORIES=     graphics
MASTER_SITES=   http://at.sakura.ne.jp/~suz/arc/

MAINTAINER=     fk200329@fsinet.or.jp
HOMEPAGE=	http://www.NetBSD.org/Ports/hpcmips/mgl2.html
COMMENT=	Graphics library for NEC Mobilegear/PocketBSD, NetBSD/hpcmips

DEPENDS+=	mglfonts>=0.1:../../fonts/mglfonts

USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes
USE_X11=	yes

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

ONLY_FOR_PLATFORM=	*-*-arm *-*-i386 *-*-mipsel

.include "../../mk/bsd.prefs.mk"

pre-configure:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/utils/mglcons.sh \
		> ${WRKSRC}/utils/mglcons.sh.new
	${MV} ${WRKSRC}/utils/mglcons.sh.new ${WRKSRC}/utils/mglcons.sh

post-configure:
.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "mipsel"
	@${MV} -f ${WRKSRC}/conf/config.mk-hpcmips ${WRKSRC}/conf/config.mk.tmp
.else
	@${MV} -f ${WRKSRC}/conf/config.mk-netbsd-i386-x ${WRKSRC}/conf/config.mk.tmp
.endif
.if ${OBJECT_FMT} == "a.out"
	@${SED} -e "s/ELFENV=1/ELFENV=0/" ${WRKSRC}/conf/NetBSD.mk > ${WRKSRC}/conf/NetBSD.mk.tmp
	@${MV} -f ${WRKSRC}/conf/NetBSD.mk.tmp ${WRKSRC}/conf/NetBSD.mk
	@${SED} \
		-e "s@-Wl,-rpath,${PREFIX}/lib@@" \
		${WRKSRC}/conf/config.mk.tmp > ${WRKSRC}/conf/config.mk
.else
	@${MV} -f ${WRKSRC}/conf/config.mk.tmp ${WRKSRC}/conf/config.mk
.endif

post-install:
.for i in ${MGLUTILS}
	@${INSTALL_SCRIPT} ${WRKSRC}/utils/${i} ${PREFIX}/bin/
	${CHMOD} +x ${PREFIX}/bin/${i}
.endfor
	${LN} -s mglcons.sh ${PREFIX}/bin/start_mgl.sh

	@if ${TEST} -e ${PREFIX}/bin/mglsvrcons; \
		then ${MV} -f ${PREFIX}/bin/mglsvrcons ${PREFIX}/sbin/; \
	fi
	# The following three commands are only present on hpcmips:
	@${TOUCH} ${PREFIX}/sbin/mglcalibrate
	@${TOUCH} ${PREFIX}/sbin/calibconf
	@${TOUCH} ${PREFIX}/sbin/calibdata-update
	#
	@${INSTALL_DATA_DIR} ${PREFIX}/share/mgl2
.for i in ${MGLFONTUTILS}
	@${INSTALL_DATA} ${WRKSRC}/bin/${i} ${PREFIX}/share/mgl2
.endfor
	@${RM} -f -r ${PREFIX}/share/doc/mgl2
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mgl2
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mgl2/memo
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mgl2/mgterm
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mgl2/mil
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mgl2/nine
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mgl2/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mgl2/doc
.for i in ${MGLDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/mgl2/doc/
.endfor
.for i in ${MGL2DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/mgl2/
.endfor
.for i in ${MGL2MEMOS}
	@${INSTALL_DATA} ${WRKSRC}/memo/${i} ${PREFIX}/share/doc/mgl2/memo/
.endfor
.for i in ${BINDOCS}
	@${INSTALL_DATA} ${WRKSRC}/bin/${i} ${PREFIX}/share/doc/mgl2/bin/
.endfor
.for i in ${MGTERMDOCS}
	@${INSTALL_DATA} ${WRKSRC}/mgterm/${i} ${PREFIX}/share/doc/mgl2/mgterm/
.endfor
.for i in ${MILDOCS}
	@${INSTALL_DATA} ${WRKSRC}/mil/${i} ${PREFIX}/share/doc/mgl2/mil/
.endfor
.for i in ${NINEDOCS}
	@${INSTALL_DATA} ${WRKSRC}/nine/${i} ${PREFIX}/share/doc/mgl2/nine/
.endfor

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
