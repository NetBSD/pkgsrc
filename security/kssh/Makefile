# $NetBSD: Makefile,v 1.9 2004/01/24 15:00:22 grant Exp $
#

DISTNAME=	kssh-0.7
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kssh/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://kssh.sourceforge.net/
COMMENT=	KDE Front-end to SSH

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.include "../../net/kdenetwork3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
