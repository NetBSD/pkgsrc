# $NetBSD: Makefile,v 1.5 2004/08/16 02:47:49 ben Exp $
#

DISTNAME=		hmmer-2.3.1
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.genetics.wustl.edu/pub/eddy/hmmer/2.3.1/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://hmmer.wustl.edu/
COMMENT=		Implementation of profile HMM software for protein sequence analysis

WRKSRC=			${WRKDIR}/hmmer-2.3.1
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

MAKE_FLAGS+=            MKDIR="${MKDIR}"

.include "../../mk/bsd.pkg.mk"
