# $NetBSD: Makefile,v 1.10 2003/07/17 22:53:12 grant Exp $
#

DISTNAME=		rats-2.1
CATEGORIES=		security
MASTER_SITES=		http://www.securesw.com/rats/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.securesw.com/rats/
COMMENT=		Rough Auditing Tool for Security

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--datadir=${LOCALBASE}/share/rats
ALL_TARGET=		rats

.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
