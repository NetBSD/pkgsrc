# $NetBSD: Makefile,v 1.1.1.1 2003/02/16 11:12:21 markd Exp $
#

DISTNAME=	kssh-0.7
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
