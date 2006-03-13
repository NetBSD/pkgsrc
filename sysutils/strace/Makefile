# $NetBSD: Makefile,v 1.4 2006/03/13 18:25:09 wiz Exp $
#

DISTNAME=		strace-4.5.14
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=strace/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		http://www.liacs.nl/~wichert/strace/
COMMENT=		Trace system calls

NOT_FOR_PLATFORM=	NetBSD-[012]*-* NetBSD-3.[0-9][._]*-* \
			NetBSD-3.99.[0-9]-* NetBSD-3.99.1[0-5]-*

WRKSRC=			${WRKDIR}/${DISTNAME}/${SRCBALL_NAME}
GNU_CONFIGURE=		yes

REPLACE_PERL=		strace-graph 

.include "../../mk/bsd.pkg.mk"
