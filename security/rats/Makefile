# $NetBSD: Makefile,v 1.2 2001/08/06 06:10:50 jun Exp $
#

DISTNAME=	rats-1.1
CATEGORIES=	security
MASTER_SITES=	http://www.securesw.com/rats/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.securesw.com/rats/
COMMENT=	Rough Auditing Tool for Security

DEPENDS+=	expat-*:../../textproc/expat

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-expat-include=${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
