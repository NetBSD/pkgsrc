# $NetBSD: Makefile,v 1.1.1.1 2000/11/01 16:22:39 hubertf Exp $

DISTNAME=       mgl2-alpha-019
PKGNAME=        mgl-0.1.9a
CATEGORIES=     graphics
MASTER_SITES=   http://at.sakura.ne.jp/~suz/arc/

MAINTAINER=     fk200329@fsinet.or.jp
HOMEPAGE=	http://www.netbsd.org/Ports/hpcmips/mgl2.html

DEPENDS= 	jpeg>=6b:../../graphics/jpeg \
		png>=1.0.3:../../graphics/png \
		libungif>=4.1.0:../../graphics/libungif \
		mglfonts>=0.1:../../fonts/mglfonts

USE_GMAKE= yes

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
MGLFONTUTILS=	mgl_fontcreate.c
MGLUTILS=	kill_mgl.sh mglcons.sh set_mgl.sh

ONLY_FOR_PLATFORM=	*-*-i386 *-*-mipsel

.include "../../mk/bsd.prefs.mk"

pre-build:
.if ${MACHINE_ARCH} == "mipsel"
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
	@${MKDIR} ${PREFIX}/share/mgl2
.for i in ${MGLFONTUTILS}
	@${INSTALL_DATA} ${WRKSRC}/bin/${i} ${PREFIX}/share/mgl2
.endfor
	@${RM} -f -r ${PREFIX}/share/doc/mgl2
	@${MKDIR} ${PREFIX}/share/doc/mgl2
	@${MKDIR} ${PREFIX}/share/doc/mgl2/memo
	@${MKDIR} ${PREFIX}/share/doc/mgl2/mgterm
	@${MKDIR} ${PREFIX}/share/doc/mgl2/mil
	@${MKDIR} ${PREFIX}/share/doc/mgl2/bin
	@${MKDIR} ${PREFIX}/share/doc/mgl2/doc
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

.include "../../mk/bsd.pkg.mk"
