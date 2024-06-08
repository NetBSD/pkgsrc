# $NetBSD: plasma6.mk,v 1.1 2024/06/08 00:00:40 markd Exp $

PLASMAVER?=	6.0.5
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
