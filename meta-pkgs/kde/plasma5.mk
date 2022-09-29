# $NetBSD: plasma5.mk,v 1.5 2022/09/29 00:22:13 markd Exp $

PLASMAVER?=	5.24.6
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz

#EXTRACT_USING=	gtar

.include "../../meta-pkgs/kde/Makefile.common"
