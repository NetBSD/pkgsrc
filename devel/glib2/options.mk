# $NetBSD: options.mk,v 1.3 2008/05/28 21:20:48 joerg Exp $
#
# This file is *not* included for HPUX and OSF1, as they don't have
# a working FAM implementation. 

PKG_OPTIONS_VAR =	PKG_OPTIONS.glib2

PKG_SUGGESTED_OPTIONS=	fam
PKG_SUPPORTED_OPTIONS=	fam
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfam)
PLIST.fam=		yes
FAM_ACCEPTED=		fam
.  include "../../mk/fam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fam

.  if ${OPSYS} == "IRIX"
SUBST_CLASSES+=			fam-linkage
SUBST_STAGE.fam-linkage=	pre-configure
SUBST_MESSAGE.fam-linkage=	Fixing fam linkage
SUBST_FILES.fam-linkage=	gio/fam/Makefile.in
SUBST_SED.fam-linkage=		-e 's,^FAM_LIBS =.*$$,FAM_LIBS = -lfam -lC,g'

BUILDLINK_TRANSFORM+=		l:fam:fam:C
.  endif
.endif
