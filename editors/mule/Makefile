# $NetBSD: Makefile,v 1.17 2002/11/29 00:24:48 kei Exp $

DISTNAME=	mule-2.3
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.m17n.org/mule/MulePage.en.html
COMMENT=	Multilingual GNU editing macros (editor)

CONFLICTS=	emacs-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_WNN4) || ${USE_WNN4} == YES
.include "../../inputmethod/ja-freewnn-lib/buildlink2.mk"
.endif
.if !defined(USE_CANNA) || ${USE_CANNA} == YES
.include "../../inputmethod/canna-lib/buildlink2.mk"
.endif

WRKSRC=		${WRKDIR}/mule
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes

CONFIGURE_ARGS+=	${MACHINE_ARCH}--netbsd --with-x --with-x-toolkit=lucid
CONFIGURE_ARGS+=	--terminal-face --mcpath
.if ${MACHINE_ARCH} != "alpha" && ${MACHINE_ARCH} != "sparc64"
CONFIGURE_ARGS+=	--valbits=26
.endif
CONFIGURE_ARGS+=	--bdf-path=${X11PREFIX}/lib/X11/fonts/intlfonts/bdf

.if !defined(USE_WNN4) || ${USE_WNN4} == YES
CONFIGURE_ARGS+=	--with-wnn4 --wnn-includes=${BUILDLINK_PREFIX.ja-freewnn}/include/wnn --wnn-libraries=${BUILDLINK_PREFIX.ja-freewnn}/lib
.endif

.if !defined(USE_CANNA) || ${USE_CANNA} == YES
CONFIGURE_ARGS+=	--canna --canna-includes=${BUILDLINK_PREFIX.canna}/include --canna-libraries=${BUILDLINK_PREFIX.canna}/lib
.endif

INFO_FILES=	antenews-jp canna-jp cl dired-x egg-jp emacs forms gnus mule \
		mule-jp sc vip
TEXINFO_OVERRIDE=	YES
TEXINFO_PATTERNS+=	Makefile

MAN1=		coco.1 ctags.1 etags.1 m2ps.1 mule.1

post-patch:
	@${ECHO_MSG} "===> Applying jumbo patches in info directory"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/info.patch
	@${RM} -f ${WRKSRC}/info/*.orig

# Fix character mapping for pkgsrc/fonts/intlfonts
post-install:
	${SED} \
		-e 's/etl\([0-9]*\)-latin1/lt1-40-etl/' \
		-e 's/etl\([0-9]*\)-latin\([0-9]\)/lt\2-\1-etl/' \
		-e 's/jiskan24/j83-48/' \
		< ${WRKSRC}/etc/CHARSETS > ${PREFIX}/lib/mule/19.28/etc/CHARSETS
	#diff -u		${WRKSRC}/etc/CHARSETS ${PREFIX}/lib/mule/19.28/etc/CHARSETS

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
