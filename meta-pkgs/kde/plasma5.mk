# $NetBSD: plasma5.mk,v 1.3 2019/08/28 19:36:53 markd Exp $

PLASMAVER?=	5.16.4
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz

#EXTRACT_USING=	gtar

.include "../../meta-pkgs/kde/Makefile.common"
