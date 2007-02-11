# $NetBSD: Makefile,v 1.18 2007/02/11 05:21:56 tv Exp $
#
# WARNING: updating this package (as of the 1.1/1.2 releases) means
# updating BUILDLINK_ABI_DEPENDS in buildlink3.mk and a PKGREVISION
# bump of all first-level dependents.  This is because the shlib
# name contains the exact libevent release number, preventing it
# from being ABI compatible across releases until this is fixed.
# [tvierling 20070210]

DISTNAME=	libevent-1.2a
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/libevent/
COMMENT=	Asynchronous event notification library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	verify

.include "../../mk/bsd.pkg.mk"
