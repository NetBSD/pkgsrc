# $NetBSD: Makefile,v 1.2 2013/07/15 15:14:29 ryoon Exp $
#

DISTNAME=		libedit-20130712-3.1
PKGNAME=		editline-3.1.20130712
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.thrysoee.dk/editline/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://www.thrysoee.dk/editline/
COMMENT=		NetBSD Editline library (libedit) for generic line editing
LICENSE=		modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		automake autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
