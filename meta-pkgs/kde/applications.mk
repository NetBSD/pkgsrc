# $NetBSD: applications.mk,v 1.1 2018/04/11 11:34:57 markd Exp $

KAPPSVER?=	17.12.3
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=applications/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
