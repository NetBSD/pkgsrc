# $NetBSD: Makefile,v 1.1.1.1 1999/07/14 05:41:47 sakamoto Exp $
#

DISTNAME=	plptools-0.3
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.to.com/pub/psion/

MAINTAINER=	sakamoto@netbsd.org

DEPENDS=	readline-2.2:../../devel/readline

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include/"

.include "../../mk/bsd.pkg.mk"
