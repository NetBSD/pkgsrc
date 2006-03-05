# $NetBSD: Makefile,v 1.3 2006/03/05 09:19:03 christos Exp $
#

DISTNAME=		strace-4.5.14
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=strace/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		http://www.liacs.nl/~wichert/strace/
COMMENT=		Trace system calls

WRKSRC=			${WRKDIR}/${DISTNAME}/${SRCBALL_NAME}
GNU_CONFIGURE=		yes

REPLACE_PERL=		strace-graph 

.include "../../mk/bsd.pkg.mk"
