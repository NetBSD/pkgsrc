# $NetBSD: Makefile,v 1.5 2003/08/28 20:05:21 xtraeme Exp $
#

DISTNAME=	kssh-0.7
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kssh/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://kssh.sourceforge.net/
COMMENT=	KDE Front-end to SSH

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../net/kdenetwork3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
