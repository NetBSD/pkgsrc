# $NetBSD: Makefile,v 1.6 2000/06/01 11:23:17 rh Exp $
#

DISTNAME=	plptools-0.4
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.to.com/pub/psion/

MAINTAINER=	sakamoto@netbsd.org

DEPENDS=	readline-4.0:../../devel/readline

BROKEN=		plptools does not work correctly

USE_PKGLIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include/" LIBS="-ltermlib"

.include "../../mk/bsd.pkg.mk"
