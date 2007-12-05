# $NetBSD: Makefile,v 1.10 2007/12/05 16:30:59 christos Exp $
#

DISTNAME=		strace-4.5.15
#PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=strace/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/strace/
COMMENT=		Trace system calls

BROKEN_IN=		pkgsrc-2006Q4

#			NetBSD < 3.99.16
NOT_FOR_PLATFORM=	NetBSD-[012]*-* NetBSD-3.[0-9][._]*-* \
			NetBSD-3.99.[0-9]-* NetBSD-3.99.1[0-5]-*
NOT_FOR_PLATFORM+=	DragonFly-*-*

GNU_CONFIGURE=		yes

REPLACE_PERL=		strace-graph

.include "../../mk/bsd.pkg.mk"
