# $NetBSD: Makefile,v 1.10 2008/06/20 01:09:31 joerg Exp $
#

DISTNAME=	scdp-1.0b
PKGNAME=	scdp-1.0.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scdp/}

MAINTAINER=	arved@arved.at
HOMEPAGE=	http://sourceforge.net/projects/scdp/
COMMENT=	Program to send Cisco Discovery Protocol packets

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	configure
SUBST_SED.conf=		-e "s|libnet-config|libnet10-config|g"
SUBST_MESSAGE.conf=	Fixing configuration script.

.include "../../devel/libnet10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
