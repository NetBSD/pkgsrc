# $NetBSD: Makefile,v 1.21 2006/03/04 21:30:34 jlam Exp $
#

DISTNAME=	kssh-0.7
PKGREVISION=	11
CATEGORIES=	security kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kssh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kssh.sourceforge.net/
COMMENT=	KDE Front-end to SSH

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../net/kdenetwork3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
