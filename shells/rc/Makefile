# $NetBSD: Makefile,v 1.17 2005/03/24 21:13:00 wiz Exp $

DISTNAME=       rc-1.6
CATEGORIES=	shells plan9
MASTER_SITES=   http://www.star.le.ac.uk/%7Etjg/rc/release/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.star.le.ac.uk/%7Etjg/rc/
COMMENT=	Unix incarnation of the plan9 shell

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-history

USE_PKGINSTALL=	yes
PKG_SHELL=	${PREFIX}/bin/rc

.include "../../mk/bsd.pkg.mk"
