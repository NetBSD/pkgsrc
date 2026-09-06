# $NetBSD: applications.mk,v 1.12 2026/09/06 11:02:43 markd Exp $

KAPPSVER?=	26.08.0
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=release-service/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.if !defined(STILL_KF5)
USE_CXX_FEATURES+=	c++20
.endif

.include "../../meta-pkgs/kde/Makefile.common"
