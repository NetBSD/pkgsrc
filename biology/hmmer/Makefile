# $NetBSD: Makefile,v 1.13 2012/09/11 20:32:12 asau Exp $
#

DISTNAME=		hmmer-2.3.2
CATEGORIES=		biology
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://hmmer.janelia.org/
COMMENT=		Implementation of profile HMM software for protein sequence analysis

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

MAKE_FLAGS+=		MKDIR=${MKDIR:Q}

.include "../../mk/bsd.pkg.mk"
