# $NetBSD: Makefile,v 1.3 2001/02/17 18:24:51 wiz Exp $
#

DISTNAME=	maildrop-1.2.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.flounder.net/~mrsam/maildrop/
COMMENT=	mail delivery agent with filtering abilities

.if make(install-run-depends)	# only needed for building
USE_PERL5=	YES
.endif

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-db=db

.include "../../mk/bsd.pkg.mk"
