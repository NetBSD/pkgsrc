# $NetBSD: options.mk,v 1.1 2007/08/29 23:11:38 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgcrypt
PKG_SUPPORTED_OPTIONS=	idea

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Midea)
# use of IDEA as crypto function
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

USE_TOOLS+=		automake

pre-configure:
	cd ${WRKSRC} && autoreconf -i -v
.endif
