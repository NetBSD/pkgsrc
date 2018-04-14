# $NetBSD: applications.mk,v 1.2 2018/04/14 03:33:19 markd Exp $

KAPPSVER?=	18.04.0
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=applications/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
