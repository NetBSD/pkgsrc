# $NetBSD: Makefile,v 1.3 2003/07/13 13:53:10 wiz Exp $
#

DISTNAME=	kssh-0.7
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kssh/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://kssh.sourceforge.net/
COMMENT=	KDE Front-end to SSH

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../net/kdenetwork3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
