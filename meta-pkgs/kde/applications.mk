# $NetBSD: applications.mk,v 1.9 2023/08/03 02:10:31 markd Exp $

KAPPSVER?=	23.04.3
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=release-service/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
