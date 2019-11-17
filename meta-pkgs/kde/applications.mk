# $NetBSD: applications.mk,v 1.4 2019/11/17 02:23:38 markd Exp $

KAPPSVER?=	19.08.3
CATEGORIES+=	kde
MASTER_SITES?=	${MASTER_SITE_KDE:=applications/${KAPPSVER}/src/}
EXTRACT_SUFX?=	.tar.xz

.include "../../meta-pkgs/kde/Makefile.common"
