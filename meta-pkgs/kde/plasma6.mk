# $NetBSD: plasma6.mk,v 1.2 2024/06/09 00:42:14 markd Exp $

PLASMAVER?=	6.0.5
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz
PKGNAME?=	plasma6-${DISTNAME}

.include "../../meta-pkgs/kde/Makefile.common"
