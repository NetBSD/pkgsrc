# $NetBSD: Makefile,v 1.8 2002/08/25 21:50:43 jlam Exp $
#

DISTNAME=		rats-1.4
CATEGORIES=		security
MASTER_SITES=		http://www.securesw.com/rats/

MAINTAINER=		tech-pkg-ja@jp.netbsd.org
HOMEPAGE=		http://www.securesw.com/rats/
COMMENT=		Rough Auditing Tool for Security

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--libdir=${LOCALBASE}/share/rats
ALL_TARGET=		rats

.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
