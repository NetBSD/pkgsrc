# $NetBSD: Makefile,v 1.13 2002/06/12 04:30:32 sakamoto Exp $

DISTNAME=	mule-2.3
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.m17n.org/mule/MulePage.en.html
COMMENT=	Multilingual GNU editing macros (editor)

CONFLICTS=	emacs-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_WNN4) || ${USE_WNN4} == YES
.include "../../inputmethod/ja-freewnn-lib/buildlink.mk"
.endif
.if !defined(USE_CANNA) || ${USE_CANNA} == YES
.include "../../inputmethod/canna-lib/buildlink.mk"
.endif

WRKSRC=		${WRKDIR}/mule
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	${MACHINE_ARCH}--netbsd --with-x --with-x-toolkit=lucid
CONFIGURE_ARGS+=	--terminal-face --mcpath
.if ${MACHINE_ARCH} != "alpha" && ${MACHINE_ARCH} != "sparc64"
CONFIGURE_ARGS+=	--valbits=26
.endif

.if !defined(USE_WNN4) || ${USE_WNN4} == YES
CONFIGURE_ARGS+=	--with-wnn4 --wnn-includes=${BUILDLINK_DIR}/include/wnn --wnn-libraries=${BUILDLINK_DIR}/lib
.endif

.if !defined(USE_CANNA) || ${USE_CANNA} == YES
CONFIGURE_ARGS+=	--canna --canna-includes=${BUILDLINK_DIR}/include --canna-libraries=${BUILDLINK_DIR}/lib
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

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
