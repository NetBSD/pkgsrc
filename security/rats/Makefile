# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:40 jlam Exp $
#

DISTNAME=	rats-1.1
CATEGORIES=	security
MASTER_SITES=	http://www.securesw.com/rats/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.securesw.com/rats/
COMMENT=	Rough Auditing Tool for Security

DEPENDS+=	expat-[0-9]*:../../textproc/expat

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-expat-include=${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
