# $NetBSD: applications.mk,v 1.8 2022/09/29 00:22:13 markd Exp $

KAPPSVER?=	22.08.1
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=release-service/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
