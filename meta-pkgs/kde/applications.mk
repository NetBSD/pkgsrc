# $NetBSD: applications.mk,v 1.3 2019/08/28 03:10:23 markd Exp $

KAPPSVER?=	19.08.0
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=applications/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
