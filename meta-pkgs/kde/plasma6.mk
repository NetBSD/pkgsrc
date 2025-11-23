# $NetBSD: plasma6.mk,v 1.3 2025/11/23 19:52:14 markd Exp $

PLASMAVER?=	6.5.2
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz
PKGNAME?=	plasma6-${DISTNAME}

USE_CXX_FEATURES+=	c++20

.include "../../meta-pkgs/kde/Makefile.common"
