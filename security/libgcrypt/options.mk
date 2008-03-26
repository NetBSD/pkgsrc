# $NetBSD: options.mk,v 1.2 2008/03/26 20:09:43 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgcrypt
PKG_SUPPORTED_OPTIONS=	idea

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} != "Darwin"
.  include "../../mk/compiler.mk"
# GCC 3.x (at least 3.3.3 on NetBSD) fails to compile asm() call in
# cipher/rijndael.c:do_padlock()
.  if empty(CC_VERSION:Mgcc-3.*)
PKG_SUPPORTED_OPTIONS+=	via-padlock
PKG_SUGGESTED_OPTIONS+=	via-padlock
.  endif
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Midea)
# Use of IDEA as crypto function.
LICENSE=	idea-license
RESTRICTED=     Commercial distribution is claimed to require a license.
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}

PATCH_SITES=		http://www.kfwebs.com/
PATCHFILES=		libgcrypt-1.2.4-idea.diff.bz2
PATCH_DIST_STRIP=	-p1

SUBST_CLASSES+=		idea
SUBST_STAGE.idea=	post-patch
SUBST_FILES.idea=	cipher/idea.c
SUBST_SED.idea=		-e 's,^.*SIZEOF_UNSIGNED_LONG.*$$,,'

USE_TOOLS+=		autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -i -v
.endif

.if empty(PKG_OPTIONS:Mvia-padlock)
# Disable VIA Padlock support.
CONFIGURE_ARGS+=        --disable-padlock-support
.endif
