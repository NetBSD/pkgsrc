# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/11/27 13:01:16 jdolecek Exp $
#
# Net_SMTP was bundled with PHP 4.x, but has been pushed to pear
# in PHP 5.x. If we build for PHP4, use the bundled version, otherwise 
# force dependance and install of this package.

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NETSOCKET_BUILDLINK3_MK:=	${NETSOCKET_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pear-netsmtp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npear-netsmtp}
BUILDLINK_PACKAGES+=	pear-netsmtp

.if !empty(NETSOCKET_BUILDLINK3_MK:M+)

BUILDLINK_DEPENDS.pear-netsmtp+=	pear-Net_SMTP>=1.2.6
BUILDLINK_PKGSRCDIR.pear-netsmtp?=	../../net/pear-Net_SMTP
BUILDLINK_DEPMETHOD.pear-netsmtp?=	full

.endif	# NETSOCKET_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
