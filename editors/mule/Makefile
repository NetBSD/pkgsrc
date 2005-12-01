# $NetBSD: Makefile,v 1.34 2005/12/01 18:13:24 wiz Exp $

DISTNAME=	mule-2.3
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.m17n.org/mule/MulePage.en.html
COMMENT=	Multilingual GNU editing macros (editor)

CONFLICTS=	emacs-[0-9]*

# build PATH in the dumped mule is not a problem
CHECK_WRKREF_SKIP+=	${PREFIX}/bin/mule
CHECK_WRKREF_SKIP+=	${PREFIX}/bin/mule-19.28

WRKSRC=		${WRKDIR}/mule
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANDIR=	${PREFIX}/${PKGMANDIR}/man1
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	${MACHINE_ARCH}--netbsd --with-x --with-x-toolkit=lucid
CONFIGURE_ARGS+=	--terminal-face --mcpath
.if ${MACHINE_ARCH} != "alpha" && ${MACHINE_ARCH} != "sparc64"
CONFIGURE_ARGS+=	--valbits=26
.endif
CONFIGURE_ARGS+=	--bdf-path=${X11PREFIX}/lib/X11/fonts/intlfonts/bdf

.include "options.mk"

USE_MAKEINFO=	YES
INFO_FILES=	CCL ISO2022 R2L XFONT antenews-jp canna-jp cl dired-x
INFO_FILES+=	egg egg-jp emacs forms gnus kbd-trans languages m2ps mule
INFO_FILES+=	mule-jp quail sc terminology vip

MAN1=		coco.1 ctags.1 etags.1 m2ps.1 mule.1

.include "../../mk/x11.buildlink3.mk"

# Fix character mapping for pkgsrc/fonts/intlfonts
post-install:
	${SED} \
		-e 's/etl\([0-9]*\)-latin1/lt1-40-etl/' \
		-e 's/etl\([0-9]*\)-latin\([0-9]\)/lt\2-\1-etl/' \
		-e 's/jiskan24/j83-48/' \
		< ${WRKSRC}/etc/CHARSETS > ${PREFIX}/lib/mule/19.28/etc/CHARSETS
	#diff -u		${WRKSRC}/etc/CHARSETS ${PREFIX}/lib/mule/19.28/etc/CHARSETS
.for f in info/CCL.orig info/ISO2022.orig info/R2L.orig info/XFONT.orig \
info/antenews-jp.orig info/canna-jp.orig info/egg-jp-1.orig \
info/egg-jp-2.orig info/egg-jp.orig info/egg.orig info/kbd-trans.orig \
info/languages.orig info/m2ps.orig info/mule-jp-1.orig info/mule-jp-2.orig \
info/mule-jp-3.orig info/mule-jp.orig info/mule.orig info/quail.orig \
info/terminology.orig
	${RM} ${PREFIX}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
