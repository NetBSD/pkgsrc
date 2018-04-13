# $NetBSD: plasma5.mk,v 1.2 2018/04/13 22:02:39 markd Exp $

PLASMAVER?=	5.12.4
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz

#EXTRACT_USING=	gtar

.include "../../meta-pkgs/kde/Makefile.common"
