# $NetBSD: applications.mk,v 1.11 2025/12/21 09:45:08 markd Exp $

KAPPSVER?=	25.08.3
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=release-service/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.if !defined(STILL_KF5)
USE_CXX_FEATURES+=	c++20
.endif

.include "../../meta-pkgs/kde/Makefile.common"
