# $NetBSD: Makefile,v 1.1.1.1 2000/11/21 05:21:08 kei Exp $

DISTNAME=	mule-2.3
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.m17n.org/mule/MulePage.en.html

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_WNN4) || ${USE_WNN4} == YES
DEPENDS+=	ja-FreeWnn-lib-1.10:../../japanese/freewnn-lib
.endif
.if !defined(USE_CANNA) || ${USE_CANNA} == YES
DEPENDS+=	Canna-lib-3.5b2:../../japanese/canna-lib
.endif

WRKSRC=		${WRKDIR}/mule
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GTEXINFO=	yes

CONFIGURE_ARGS+=	${MACHINE_ARCH}--netbsd --with-x --with-x-toolkit=lucid
CONFIGURE_ARGS+=	--terminal-face --mcpath
.if ${MACHINE_ARCH} != "alpha" && ${MACHINE_ARCH} != "sparc64"
CONFIGURE_ARGS+=	--valbits=26
.endif

# Find X11 libraries with xpkgwedge
.if defined(USE_LOCALBASE_FOR_X11)
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/inc
lude
.endif

.if !defined(USE_WNN4) || ${USE_WNN4} == YES
CONFIGURE_ARGS+=	--with-wnn4 --wnn-includes=${LOCALBASE}/include/wnn --wnn-libraries=${LOCALBASE}/lib
.endif

.if !defined(USE_CANNA) || ${USE_CANNA} == YES
CONFIGURE_ARGS+=	--with-canna --canna-includes=${LOCALBASE}/include/canna --canna-libraries=${LOCALBASE}/lib
.endif

INFO_FILES=	antenews-jp canna-jp cl dired-x egg-jp emacs forms gnus mule \
		mule-jp sc vip

MAN1=		coco.1 ctags.1 etags.1 m2ps.1 mule.1

post-patch:
	@${ECHO_MSG} "===> Applying jumbo patches in info directory"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/info.patch
	@${RM} -f ${WRKSRC}/info/*.orig

.include "../../mk/bsd.pkg.mk"
