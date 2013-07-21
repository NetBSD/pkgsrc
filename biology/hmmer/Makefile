# $NetBSD: Makefile,v 1.14 2013/07/21 15:58:51 wen Exp $
#

DISTNAME=		hmmer-3.0
CATEGORIES=		biology
MASTER_SITES=		${MASTER_SITE_GENTOO:=distfiles/} \
			http://selab.janelia.org/software/hmmer3/3.0/ \
			ftp://selab.janelia.org/pub/software/hmmer3/3.0/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://hmmer.janelia.org/
COMMENT=		Implementation of profile HMM software for protein sequence analysis
LICENSE=		gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

MAKE_FLAGS+=		MKDIR=${MKDIR:Q}

.include "../../mk/bsd.pkg.mk"
