# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/11/01 21:36:44 jdolecek Exp $
#
# Net_Socket was bundled with PHP 4.x, but has been pushed to pear
# in PHP 5.x. If we build for PHP4, use the bundled version, otherwise 
# force dependance and install of this package.

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NETSOCKET_BUILDLINK3_MK:=	${NETSOCKET_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pear-netsocket
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npear-netsocket}
BUILDLINK_PACKAGES+=	pear-netsocket

.if !empty(NETSOCKET_BUILDLINK3_MK:M+)

BUILDLINK_DEPENDS.pear-netsocket+=	pear-Net_Socket>=1.0.1
BUILDLINK_PKGSRCDIR.pear-netsocket?=	../../wip/pear-Net_Socket
BUILDLINK_DEPMETHOD.pear-netsocket?=	full

.endif	# NETSOCKET_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
