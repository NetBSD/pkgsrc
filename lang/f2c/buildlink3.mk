# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:48 joerg Exp $

BUILDLINK_TREE+=	f2c

.if !defined(F2C_BUILDLINK3_MK)
F2C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.f2c+=		f2c>=20001205nb3
BUILDLINK_ABI_DEPENDS.f2c+=	f2c>=20001205nb8
BUILDLINK_PKGSRCDIR.f2c?=	../../lang/f2c

# The f2c-f77 script takes some environment variables to override hardcoded
# values for the compiler and C preprocessor.
#
CONFIGURE_ENV+=         CC_f2c=${CC:Q}
CONFIGURE_ENV+=         CPP=${CPP:Q}
MAKE_ENV+=              CC_f2c=${CC:Q}
MAKE_ENV+=              CPP=${CPP:Q}
.endif # F2C_BUILDLINK3_MK

BUILDLINK_TREE+=	-f2c
