# $NetBSD: Makefile,v 1.8 1998/10/01 19:29:39 frueauf Exp $

DISTNAME=		tgif-3.0-p17
PKGNAME=		tgif-3.0p17x
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/tgif

MAINTAINER=		mcmahill@alum.mit.edu
HOMEPAGE=		http://bourbon.cs.umd.edu:8001/tgif/tgif.html

CONFLICTS=		tgif-3.0p16

USE_IMAKE=		yes

# patch tgif-3.0-patch17x is supplied in the package as
# patches/patch-ac.  It fixes a bug that causes imported EPS files
# to print with an offset.

.include "../../mk/bsd.pkg.mk"
