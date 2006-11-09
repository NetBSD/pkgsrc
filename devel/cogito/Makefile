# $NetBSD: Makefile,v 1.3 2006/11/09 02:19:59 rillig Exp $
#

DISTNAME=		cogito-0.18
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.kernel.org/pub/software/scm/cogito/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.kernel.org/pub/software/scm/cogito/
COMMENT=		Version control system of the Linux kernel

USE_TOOLS+=		gmake bash:run
MAKE_FLAGS+=		prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
