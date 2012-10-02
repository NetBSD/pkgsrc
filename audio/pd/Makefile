# $NetBSD: Makefile,v 1.4 2012/10/02 23:48:04 asau Exp $
#

DISTNAME=	pd-0.43-0.src
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/-0.src/.0/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pure-data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://puredata.info/
COMMENT=	Real-time graphical programming environment for audio+video
LICENSE=	modified-bsd

DEPENDS+=	tcl-[0-9]*:../../lang/tcl
DEPENDS+=	tk-[0-9]*:../../x11/tk

WRKSRC=		${WRKDIR}/pd-0.43-0
USE_TOOLS+=	autoconf automake gmake msgfmt pkg-config
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
REPLACE_SH=	tcl/pd-gui.tcl

LDFLAGS.SunOS+=		-lsocket -lnsl

PKGCONFIG_OVERRIDE+=	pd.pc.in

SUBST_CLASSES+=		tclsh
SUBST_SED.tclsh=	-e "s,/usr/bin/tclsh,${PREFIX}/bin/tclsh,"
SUBST_MESSAGE.tclsh=	Fix path to tclsh.
SUBST_STAGE.tclsh=	pre-build
SUBST_FILES.tclsh=	tcl/pkg_mkIndex.tcl

SUBST_CLASSES+=		device
SUBST_SED.device=	-e "s,/dev/dsp,${DEVOSSAUDIO},"
SUBST_MESSAGE.device=	Fix path to audio device.
SUBST_STAGE.device=	pre-build
SUBST_FILES.device=	src/s_audio_oss.c

SUBST_CLASSES+=		doc
SUBST_SED.doc=		-e "s,\\.\\./doc/,${PREFIX}/share/doc/pd/doc/,"
SUBST_SED.doc+=		-e "s,.::sys_libdir/doc/,${PREFIX}/share/doc/pd/doc/,"
SUBST_SED.doc+=		-e "s,menu_doc_open doc/,menu_doc_open ${PREFIX}/share/doc/pd/doc/,"
SUBST_SED.doc+=		-e "s,/doc/5.reference,/share/doc/pd/doc/5.reference,"
SUBST_SED.doc+=		-e "s,PD_BASEDIR/doc/,${PREFIX}/share/doc/pd/doc/,"
SUBST_SED.doc+=		-e "s,/usr/local/bin/pd/doc/,${PREFIX}/share/doc/pd/doc/,"
SUBST_SED.doc+=		-e "s,/usr/bin/pd/doc/,${PREFIX}/share/doc/pd/doc/,"
SUBST_MESSAGE.doc=	Fix path to docs.
SUBST_STAGE.doc=	pre-build
SUBST_FILES.doc=	doc/1.manual/1.introduction.txt
SUBST_FILES.doc+=	doc/4.data.structures/14.partialtracer.pd
SUBST_FILES.doc+=	extra/loop~/loop~-help.pd
SUBST_FILES.doc+=	extra/loop~/test-loop~.pd
SUBST_FILES.doc+=	man/pd.1
SUBST_FILES.doc+=	src/s_main.c
SUBST_FILES.doc+=	tcl/pd_menucommands.tcl
SUBST_FILES.doc+=	tcl/pd_menus.tcl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
EXTERNAL_EXTENSION=	d_fat
.elif ${OPSYS} == "Linux"
EXTERNAL_EXTENSION=	pd_linux
.else
EXTERNAL_EXTENSION=	# empty
.endif

PLIST_SUBST+=		EXTERNAL_EXTENSION=${EXTERNAL_EXTENSION:Q}

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
