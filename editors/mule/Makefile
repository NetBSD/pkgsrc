# $NetBSD: Makefile,v 1.26 2004/04/19 21:40:52 xtraeme Exp $

DISTNAME=	mule-2.3
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.m17n.org/mule/MulePage.en.html
COMMENT=	Multilingual GNU editing macros (editor)

CONFLICTS=	emacs-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_WNN4) || ${USE_WNN4} == YES
.include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
.endif
.if !defined(USE_CANNA) || ${USE_CANNA} == YES
.include "../../inputmethod/canna-lib/buildlink3.mk"
.endif

WRKSRC=		${WRKDIR}/mule
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes

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

USE_MAKEINFO=	YES
INFO_FILES=	CCL ISO2022 R2L XFONT antenews-jp canna-jp cl dired-x
INFO_FILES+=	egg egg-jp emacs forms gnus kbd-trans languages m2ps mule
INFO_FILES+=	mule-jp quail sc terminology vip

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

.include "../../mk/bsd.pkg.mk"
