# $NetBSD: Makefile,v 1.9 2007/02/22 19:26:09 wiz Exp $
#

DISTNAME=		hmmer-2.3.2
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.genetics.wustl.edu/pub/eddy/hmmer/2.3.2/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://hmmer.wustl.edu/
COMMENT=		Implementation of profile HMM software for protein sequence analysis

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

MAKE_FLAGS+=		MKDIR=${MKDIR:Q}

.include "../../mk/bsd.pkg.mk"
