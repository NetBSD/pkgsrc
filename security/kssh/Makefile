# $NetBSD: Makefile,v 1.16 2005/04/11 21:47:12 tv Exp $
#

DISTNAME=	kssh-0.7
PKGREVISION=	8
CATEGORIES=	security kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kssh/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://kssh.sourceforge.net/
COMMENT=	KDE Front-end to SSH

USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../net/kdenetwork3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
