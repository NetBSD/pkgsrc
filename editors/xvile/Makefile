# $NetBSD: Makefile,v 1.81 2022/07/04 20:10:53 wiz Exp $

DISTNAME=		vile-9.8v
PKGNAME=		x${DISTNAME}
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.invisible-island.net/vile/current/ \
			https://invisible-mirror.net/archives/vile/current/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://invisible-island.net/vile/
COMMENT=		VI Like Emacs, X11 version -- a fully "X aware" vi work-alike
LICENSE=		gnu-gpl-v2

DISTINFO_FILE=		${.CURDIR}/../../editors/vile/distinfo
PATCHDIR=		${.CURDIR}/../../editors/vile/patches

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-imake
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--with-libdir-path=${FILTERDIR:Q}
CONFIGURE_ARGS+=	--with-startup-path=${DATADIR:Q}

MAKE_FILE=		makefile
INSTALL_TARGET=		install install-doc install-perl

REPLACE_PERL=		perl/vileget
REPLACE_PERL+=		macros/lxvile
REPLACE_PERL+=		macros/lxvile-fonts
USE_TOOLS+=		perl:run

DATADIR=		${PREFIX}/share/xvile
FILTERDIR=		${PREFIX}/libexec/xvile
EGDIR=			${PREFIX}/share/examples/xvile

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-screen=Xaw3d
CONFIGURE_ARGS+=	--with-Xaw3d
.else
CONFIGURE_ARGS+=	--with-screen=Xaw
.endif
CONFIGURE_ARGS+=	--with-xpm

pre-configure:
	for f in							\
		${WRKDIR}/${DISTNAME}/makefile.in			\
		${WRKDIR}/${DISTNAME}/filters/makefile.in; do		\
		${MV} $$f $$f.bak;					\
		sed -e '/^datadir[ 	]*=[ 	]*@datadir@/s%/vile%/xvile%' $$f.bak >$$f; \
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/vileget 			\
		${DESTDIR}${PREFIX}/bin/xvileget
	${RM} -f ${DESTDIR}${PREFIX}/bin/vileget
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	set -e;								\
	for f in filters/spell.rc filters/filters.rc			\
		macros/digraphs.rc macros/pictmode.rc			\
		macros/manpage.rc visvile/visvile.rc; do		\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${EGDIR};	\
	done

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
