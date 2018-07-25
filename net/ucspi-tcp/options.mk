# $NetBSD: options.mk,v 1.7 2018/07/25 16:19:16 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucspi-tcp
PKG_SUPPORTED_OPTIONS+=	inet6 ucspi-tcp-nodefaultrbl
PKG_SUGGESTED_OPTIONS+=	inet6 ucspi-tcp-nodefaultrbl

.include "../../mk/bsd.options.mk"

DESTDIR_PATCH=			ucspi-tcp-0.88-destdir-20180725.patch
PATCHFILES+=			${DESTDIR_PATCH}
SITES.${DESTDIR_PATCH}=		https://schmonz.com/qmail/ucspitcpdestdir/

PLIST_VARS+=			inet6
.if !empty(PKG_OPTIONS:Minet6)
IPV6_PATCH=			ucspi-tcp-0.88-ipv6.diff20.bz2
PATCHFILES+=			${IPV6_PATCH}
SITES.${IPV6_PATCH}=		http://www.fefe.de/ucspi/
PATCH_DIST_STRIP.${IPV6_PATCH}=	-p1
PLIST.inet6=			yes

SUBST_CLASSES+=		hier
SUBST_STAGE.hier=	pre-configure
SUBST_MESSAGE.hier=	Fixing manpage path.
SUBST_FILES.hier=	hier.c
SUBST_SED.hier=		-e 's,man,${PKGMANDIR},'
.endif

.if !empty(PKG_OPTIONS:Mucspi-tcp-nodefaultrbl)
NODEFAULTRBL_PATCH=		rblsmtpd-nodefaultrbl.patch
PATCHFILES+=			${NODEFAULTRBL_PATCH}
SITES.${NODEFAULTRBL_PATCH}=	http://pyropus.ca/software/misc/
PATCH_DIST_STRIP.${NODEFAULTRBL_PATCH}=	-p1
.endif
