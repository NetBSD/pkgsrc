# $NetBSD: Makefile,v 1.4 2001/04/26 16:35:30 wiz Exp $
#

DISTNAME=	maildrop-1.2.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.flounder.net/~mrsam/maildrop/
COMMENT=	mail delivery agent with filtering abilities

BUILD_DEPENDS+=	perl>=5.6.0:../../lang/perl5

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-db=db

.include "../../mk/bsd.pkg.mk"
