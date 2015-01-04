# $NetBSD: Makefile,v 1.6 2015/01/04 05:43:31 dholland Exp $

DISTNAME=	py-sysctl-0.1
PKGNAME=	${PYPKGPREFIX}-sysctl-0.1
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/cherry/

# Depends on NetBSD's dynamic sysctl discovery API.
# (If you have another OS that supports this, add it here)
ONLY_FOR_PLATFORM+=	NetBSD-*-*

MAINTAINER=	cherry@zyx.in
COMMENT=	Python interface to sysctl(3)

PYDISTUTILSPKG=	# yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
