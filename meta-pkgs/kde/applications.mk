# $NetBSD: applications.mk,v 1.5 2020/02/02 02:31:17 markd Exp $

KAPPSVER?=	19.12.1
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=release-service/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
