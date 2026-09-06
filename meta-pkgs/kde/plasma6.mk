# $NetBSD: plasma6.mk,v 1.4 2026/09/06 10:23:28 markd Exp $

PLASMAVER?=	6.7.4
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz
PKGNAME?=	plasma6-${DISTNAME}

USE_CXX_FEATURES+=	c++20

.include "../../meta-pkgs/kde/Makefile.common"
