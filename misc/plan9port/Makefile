# $NetBSD: Makefile,v 1.11 2025/01/28 17:41:20 vins Exp $

DISTNAME=	plan9port-20240717
PKGREVISION=	1
CATEGORIES=	misc plan9
MASTER_SITES=	${MASTER_SITE_GITHUB:=9fans/}
GITHUB_TAG=	a2567fcac9851e5cc965a236679f568b0e79cff2

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://9fans.github.io/plan9port/
COMMENT=	Plan 9 from User Space
# mostly MIT (see LICENSE)
# certain fonts may NOT be redistributed separately.
LICENSE=	mit AND zlib

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run perl pax sed

MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

PTHREAD_AUTO_VARS=		yes
BUILDLINK_TRANSFORM+=		rm:-lpthread

PLAN9_TARGET=	${PREFIX}/plan9

REPLACE_BASH+=	bin/macedit
REPLACE_BASH+=	mac/9term.app/Contents/MacOS/9term
REPLACE_BASH+=	mac/Plumb.app/Contents/MacOS/plumb
REPLACE_BASH+=	src/cmd/rc/checkparse

REPLACE_PERL+=	dist/addsrclinks
REPLACE_PERL+=	dist/fixurls
REPLACE_PERL+=	unix/man/fixurls

REPLACE_INTERPRETER+=	rc
REPLACE.rc.old=		.*/bin/rc
REPLACE.rc.new=		${PLAN9_TARGET}/bin/rc
REPLACE_FILES.rc+=	bin/9.rc bin/9fs bin/Getdir bin/adict		\
			bin/doctype bin/ipso bin/lookman bin/man	\
			bin/mount bin/quote1 bin/quote2 bin/sig		\
			bin/soelim bin/spell bin/src bin/ssam		\
			bin/stack bin/troff2png bin/u.rc bin/unmount	\
			bin/upas/isspam bin/upas/msgcat bin/upas/spam	\
			bin/upas/spambox bin/upas/unspam		\
			bin/upas/unspambox acid/transcript acid/window	\
			bin/vmount bin/vwhois bin/wintext bin/yesterday	\
			dist/debian/mkpkg  dist/debian/mkrep		\
			dist/manweb dist/mkdirlist dist/mkfilelist	\
			dist/publish dist/troff/tfont			\
			mail/lib/qmail	mail/lib/remotemail		\
			mail/lib/validateattachment			\
			man/mkindex man/secindex			\
			src/cmd/9660/mk9660.rc src/cmd/dict/egfix	\
			src/cmd/dict/egfix2 src/cmd/dict/gefix		\
			src/cmd/dict/getneeds src/cmd/fossil/conf.rc	\
			src/cmd/lp/lp.rc src/cmd/lp/lpsend.rc		\
			lp/bin/* lp/daemon/* lp/process/* lp/stat/*	\
			lp/kill/generic lp/sched/FIFO lp/spooler/*	\
			src/cmd/map/map.rc src/cmd/map/mapdemo.rc	\
			src/cmd/netfiles/netfileget			\
			src/cmd/netfiles/netfileput			\
			src/cmd/netfiles/netfilestat			\
			src/cmd/postscript/printfont/printfont.rc	\
			src/cmd/spell/spell.rc				\
			src/cmd/upas/misc/mail.rc			\
			src/cmd/upas/misc/qmail				\
			src/cmd/upas/misc/remotemail			\
			src/cmd/upas/filterkit/pipefrom.sample		\
			src/cmd/venti/srv/conf.rc			\
			src/cmd/venti/srv/tester

SUBST_CLASSES+=		cc
SUBST_STAGE.cc=		pre-configure
SUBST_FILES.cc+=	INSTALL
SUBST_FILES.cc+=	bin/9c bin/9l
SUBST_VARS.cc=		CC
SUBST_MESSAGE.cc=	Defining preferred compiler.

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	src/cmd/devdraw/mkwsysrules.sh
SUBST_FILES.prefix+=	INSTALL plan9.sh acme.sh
SUBST_VARS.prefix=	PREFIX X11BASE
SUBST_MESSAGE.prefix=	Replacing PREFIX placeholders.

EGDIR=		${PREFIX}/share/examples/profile.d
CONF_FILES+=	${EGDIR}/plan9.sh \
		${PKG_SYSCONFDIR}/profile.d/plan9.sh
DOCDIR=		${PREFIX}/share/doc/plan9

MAKE_DIRS+=		${PKG_SYSCONFDIR}/profile.d

PLAN9_BUILD=		${DESTDIR}${PLAN9_TARGET}
INSTALL_ENV+=		PLAN9_TARGET=${PLAN9_TARGET}

.include "../../mk/bsd.prefs.mk"
.if exists(/dev/kmem) && ${OPSYS:M*BSD}
SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} kmem 2755
SPECIAL_PERMS+=		${PLAN9_TARGET}/bin/auxstats ${SETUID_ROOT_PERMS}
.endif

INSTALLATION_DIRS+=	bin plan9 ${EGDIR}
INSTALLATION_DIRS+=	share/doc/plan9
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

.include "options.mk"

post-extract:
.for s in acme.sh plan9.sh
	${RUN}${CP} ${FILESDIR}/${s} ${WRKSRC}
.endfor

do-configure:
	${RUN}${ECHO} "CC9='${CC}'" >> ${WRKSRC}/LOCAL.config
	${RUN}${ECHO} "CC9FLAGS='${CFLAGS}'" >> ${WRKSRC}/LOCAL.config
	${RUN}${ECHO} "LDFLAGS='${LDFLAGS}'" >> ${WRKSRC}/LOCAL.config
	${RUN}${ECHO} "FONTSRV=fontsrv"	>> ${WRKSRC}/LOCAL.config
.if ${OPSYS} == "Darwin"
	${RUN}${ECHO} "WSYSTYPE='mac'" >> ${WRKSRC}/LOCAL.config
.elif !empty(PKG_OPTIONS:Mx11)
	${RUN}${ECHO} "WSYSTYPE='x11'" >> ${WRKSRC}/LOCAL.config
.else
	${RUN}${ECHO} "WSYSTYPE='nowsys'" >> ${WRKSRC}/LOCAL.config
.endif

do-build:
	${RUN}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} ./INSTALL -b

post-build:
# Clean versioning and backup files
.for h in *.orig .gitignore .gitkeep .travis.yml
	${RUN}${FIND} ${WRKSRC} -type f -name "${h}" -delete
.endfor
	${RUN}${RM} -r ${WRKSRC}/.github

do-install:
# Move everything to the PLAN9 target.
	${RUN}cd ${WRKSRC} && ${PAX} -rw -pm . ${PLAN9_BUILD}
# Rename hard-coded paths and builds mans.
	${RUN}cd ${PLAN9_BUILD} &&			\
	  ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${SH} ./INSTALL -c
# Install docs and sample profile script.
.for f in CHANGES LICENSE README.md
	${RUN}cd ${PLAN9_BUILD} &&			\
	  ${PAX} -rw -pm ${f} ${DESTDIR}${DOCDIR}
.endfor
	${INSTALL_SCRIPT} ${PLAN9_BUILD}/plan9.sh	\
	  ${DESTDIR}${PREFIX}/share/examples/profile.d
# Delete installation files and other leftovers.
	${RUN}${FIND} ${PLAN9_BUILD} -maxdepth 1 -type f ! -name rcmain -delete
# Avoid 'executable bit is set on non-executable file'
.for x in bclib mimetype
	${RUN}${FIND} ${PLAN9_BUILD}/lib 		\
	  -type f -name ${x} -exec ${CHMOD} -x '{}' \;
.endfor
.for x in ignore namefiles names.local rewrite
	${RUN}${FIND} ${PLAN9_BUILD}/mail/lib 		\
	  -type f -name ${x} -exec ${CHMOD} -x '{}' \;
.endfor
.for x in resample.1 soelim.1 ssam.1
	${RUN}${FIND} ${PLAN9_BUILD}/man/man1		\
	  -type f -name ${x} -exec ${CHMOD} -x '{}' \;
.endfor
.for x in compress.c filter.y mkfile
	${RUN}${FIND} ${PLAN9_BUILD}/src		\
	  -type f -name ${x} -exec ${CHMOD} -x '{}' \;
.endfor
	${RUN}${CHMOD} -x ${PLAN9_BUILD}/font/MAP
	${RUN}${CHMOD} -x ${PLAN9_BUILD}/man/fonts

post-install:
# install venti/fossil conf scripts.
	${INSTALL_SCRIPT} ${WRKSRC}/src/cmd/venti/srv/conf.rc   \
		${PLAN9_BUILD}/bin/venti/conf
	${INSTALL_SCRIPT} ${WRKSRC}/src/cmd/fossil/conf.rc      \
		${PLAN9_BUILD}/bin/fossil/conf
# symlink the `compress' utility to its counterpart(s).
.for z in uncompress zcat
	${RUN}${LN} -sf ${PLAN9_TARGET}/bin/compress 	\
		${PLAN9_BUILD}/bin/${z}
.endfor
# Allow acme to be run as a standalone application.
	${INSTALL_SCRIPT} ${WRKSRC}/acme.sh		\
	  ${DESTDIR}${PREFIX}/bin/acme
	${INSTALL_DATA} ${FILESDIR}/acme.desktop	\
	  ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/dist/glendacircle.png	\
	  ${DESTDIR}${PREFIX}/share/pixmaps/acme.png

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
