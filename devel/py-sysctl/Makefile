# $NetBSD: Makefile,v 1.9 2022/01/19 17:57:14 wiz Exp $

DISTNAME=	py-sysctl-0.1
PKGNAME=	${PYPKGPREFIX}-sysctl-0.1
PKGREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/cherry/

# Depends on NetBSD's dynamic sysctl discovery API.
# (If you have another OS that supports this, add it here)
ONLY_FOR_PLATFORM+=	NetBSD-*-*

MAINTAINER=	cherry@zyx.in
COMMENT=	Python interface to sysctl(3)

EGG_NAME=	sysctl-0.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
