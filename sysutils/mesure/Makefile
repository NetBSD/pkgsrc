# $NetBSD: Makefile,v 1.1.1.1 2005/09/26 23:27:37 xtraeme Exp $
#

DISTNAME=		mesure-0.5
CATEGORIES=		sysutils
MASTER_SITES=		http://cvs.nopcode.org/ftp/mesure/\
			ftp://ftp.nopcode.org/prj/mesure/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nopcode.org/?t=mesure
COMMENT=		Tool to measure different kind of streams

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

NOT_FOR_PLATFORM+=	OpenBSD-*-*

.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
