# $NetBSD: buildlink3.mk,v 1.2 2004/01/04 23:34:07 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBNBCOMPAT_BUILDLINK3_MK:=	${LIBNBCOMPAT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libnbcompat
.endif

.if !empty(LIBNBCOMPAT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libnbcompat
BUILDLINK_DEPENDS.libnbcompat?=		libnbcompat>=20030830
BUILDLINK_PKGSRCDIR.libnbcompat?=	../../pkgtools/libnbcompat
BUILDLINK_DEPMETHOD.libnbcompat?=	build
BUILDLINK_LDADD.libnbcompat=		-lnbcompat

.  if defined(GNU_CONFIGURE)
LIBS+=	${BUILDLINK_LDADD.libnbcompat}
.  endif
.endif  # LIBNBCOMPAT_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
