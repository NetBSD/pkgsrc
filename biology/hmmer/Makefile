# $NetBSD: Makefile,v 1.12 2009/07/08 15:20:04 joerg Exp $
#

DISTNAME=		hmmer-2.3.2
CATEGORIES=		biology
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://hmmer.janelia.org/
COMMENT=		Implementation of profile HMM software for protein sequence analysis

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

MAKE_FLAGS+=		MKDIR=${MKDIR:Q}

.include "../../mk/bsd.pkg.mk"
