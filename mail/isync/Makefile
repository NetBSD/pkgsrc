# $NetBSD: Makefile,v 1.1.1.1 2002/12/07 15:12:41 cjep Exp $
#

DISTNAME=	isync-0.8
CATEGORIES=	mail net
MASTER_SITES=	http://www.cs.hmc.edu/~me/isync/

MAINTAINER=	cez+misc.pkgsrc@compsoc.man.ac.uk
HOMEPAGE=	http://www.cs.hmc.edu/~me/isync/
COMMENT=	Syncronize a maildir with an imap server

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
