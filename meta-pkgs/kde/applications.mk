# $NetBSD: applications.mk,v 1.10 2024/02/06 10:30:14 markd Exp $

KAPPSVER?=	23.08.4
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=release-service/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
