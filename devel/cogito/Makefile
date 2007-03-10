# $NetBSD: Makefile,v 1.5 2007/03/10 19:09:33 wiz Exp $
#

DISTNAME=		cogito-0.18.2
CATEGORIES=		devel
MASTER_SITES=		http://www.kernel.org/pub/software/scm/cogito/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.kernel.org/pub/software/scm/cogito/
COMMENT=		Version control system of the Linux kernel

DEPENDS+=		scmgit-[0-9]*:../../devel/scmgit

USE_TOOLS+=		gmake bash:run
MAKE_FLAGS+=		prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
