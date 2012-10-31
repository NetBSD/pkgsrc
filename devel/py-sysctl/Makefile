# $NetBSD: Makefile,v 1.5 2012/10/31 11:19:35 asau Exp $

DISTNAME=	py-sysctl-0.1
PKGNAME=	${PYPKGPREFIX}-sysctl-0.1
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/cherry/

ONLY_FOR_PLATFORM+=	NetBSD-*-*

MAINTAINER=	cherry@zyx.in
COMMENT=	Python interface to sysctl(3)

PYDISTUTILSPKG=	# yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
