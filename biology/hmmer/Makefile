# $NetBSD: Makefile,v 1.6 2004/12/01 04:01:09 minskim Exp $
#

DISTNAME=		hmmer-2.3.2
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.genetics.wustl.edu/pub/eddy/hmmer/2.3.2/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://hmmer.wustl.edu/
COMMENT=		Implementation of profile HMM software for protein sequence analysis

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

MAKE_FLAGS+=            MKDIR="${MKDIR}"

.include "../../mk/bsd.pkg.mk"
