# $NetBSD: buildlink3.mk,v 1.1 2004/05/05 18:12:11 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
BLACKDOWN_JDK13_BUILDLINK3_MK:=	${BLACKDOWN_JDK13_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	blackdown-jdk13
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nblackdown-jdk13}
BUILDLINK_PACKAGES+=	blackdown-jdk13

.if !empty(BLACKDOWN_JDK13_BUILDLINK3_MK:M+)

BUILDLINK_DEPENDS.blackdown-jdk13+=	blackdown-jdk13-[0-9]*
BUILDLINK_PKGSRCDIR.blackdown-jdk13?=	../../lang/blackdown-jdk13
BUILDLINK_DEPMETHOD.blackdown-jdk13?=   build
BUILDLINK_CPPFLAGS.blackdown-jdk13=					\
	-I${BUILDLINK_JAVA_PREFIX.blackdown-jre13}/include		\
	-I${BUILDLINK_JAVA_PREFIX.blackdown-jre13}/include/linux

.include "../../lang/blackdown-jre13/buildlink3.mk"

.endif	# BLACKDOWN_JDK13_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
