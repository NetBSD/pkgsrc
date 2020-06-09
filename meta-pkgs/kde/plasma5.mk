# $NetBSD: plasma5.mk,v 1.4 2020/06/09 06:51:46 markd Exp $

PLASMAVER?=	5.18.5
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz

#EXTRACT_USING=	gtar

.include "../../meta-pkgs/kde/Makefile.common"
