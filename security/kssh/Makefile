# $NetBSD: Makefile,v 1.7 2004/01/03 18:49:52 reed Exp $
#

DISTNAME=	kssh-0.7
PKGREVISION=	5
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
