# $NetBSD: Makefile,v 1.4 2004/03/05 21:03:27 minskim Exp $

DISTNAME=	sj3-server-2.0.1.20
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Japanese input method (server)

DEPENDS+=	sj3-server-bin>=2.0.1.20nb1:../sj3-server-bin
DEPENDS+=	sj3-dict>=2.0.1.20nb1:../sj3-dict

EXTRACT_ONLY=	# empty
NO_BUILDLINK=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
NO_CHECKSUM=	YES

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
