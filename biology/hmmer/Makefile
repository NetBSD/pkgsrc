# $NetBSD: Makefile,v 1.10 2009/05/16 23:19:19 zafer Exp $
#

DISTNAME=		hmmer-2.3.2
CATEGORIES=		biology
MASTER_SITES=		# ftp://selab.janelia.org/pub/software/hmmer/2.3.2/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://hmmer.janelia.org/
COMMENT=		Implementation of profile HMM software for protein sequence analysis

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

MAKE_FLAGS+=		MKDIR=${MKDIR:Q}

.include "../../mk/bsd.pkg.mk"
