# $NetBSD: plasma5.mk,v 1.6 2024/02/06 10:30:14 markd Exp $

PLASMAVER?=	5.27.10
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz

#EXTRACT_USING=	gtar

.include "../../meta-pkgs/kde/Makefile.common"
