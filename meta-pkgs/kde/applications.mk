# $NetBSD: applications.mk,v 1.6 2020/06/09 06:51:46 markd Exp $

KAPPSVER?=	20.04.1
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=release-service/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
