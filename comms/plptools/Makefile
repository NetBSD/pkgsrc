# $NetBSD: Makefile,v 1.4 1999/08/26 06:03:47 sakamoto Exp $
#

DISTNAME=	plptools-0.4
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.to.com/pub/psion/

MAINTAINER=	sakamoto@netbsd.org

DEPENDS=	readline-4.0:../../devel/readline

BROKEN=		"plptools is not work correctly"

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include/" LIBS="-ltermlib"

.include "../../mk/bsd.pkg.mk"
