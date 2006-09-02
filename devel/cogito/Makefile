# $NetBSD: Makefile,v 1.1.1.1 2006/09/02 20:58:22 rillig Exp $
#

DISTNAME=		cogito-0.16
CATEGORIES=		devel
MASTER_SITES=		http://www.kernel.org/pub/software/scm/cogito/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.kernel.org/pub/software/scm/cogito/
COMMENT=		Version control system of the Linux kernel

USE_TOOLS+=		gmake bash:run
MAKE_FLAGS+=		prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
