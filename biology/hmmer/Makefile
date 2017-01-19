# $NetBSD: Makefile,v 1.16 2017/01/19 18:52:03 agc Exp $
#

DISTNAME=		hmmer-3.0
CATEGORIES=		biology
MASTER_SITES=		${MASTER_SITE_GENTOO:=distfiles/}
MASTER_SITES+=		http://selab.janelia.org/software/hmmer3/3.0/
MASTER_SITES+=		ftp://selab.janelia.org/pub/software/hmmer3/3.0/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://hmmer.janelia.org/
COMMENT=		Implementation of profile HMM software for protein sequence analysis
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes

MAKE_FLAGS+=		MKDIR=${MKDIR:Q}

.include "../../mk/bsd.pkg.mk"
