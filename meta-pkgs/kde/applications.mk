# $NetBSD: applications.mk,v 1.7 2021/04/07 12:28:14 markd Exp $

KAPPSVER?=	20.12.3
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=release-service/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
