# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:15:00 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
F2C_BUILDLINK3_MK:=	${F2C_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	f2c
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nf2c}
BUILDLINK_PACKAGES+=	f2c

.if !empty(F2C_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.f2c+=	f2c>=20001205nb3
BUILDLINK_RECOMMENDED.f2c+=	f2c>=20001205nb7
BUILDLINK_PKGSRCDIR.f2c?=	../../lang/f2c
.endif	# F2C_BUILDLINK3_MK

PKG_FC=                 ${BUILDLINK_PREFIX.f2c}/bin/f2c-f77

# The f2c-f77 script takes some environment variables to override hardcoded
# values for the compiler and C preprocessor.
#
CONFIGURE_ENV+=         CC_f2c="${CC}"
CONFIGURE_ENV+=         CPP="${CPP}"
MAKE_ENV+=              CC_f2c="${CC}"
MAKE_ENV+=              CPP="${CPP}"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
