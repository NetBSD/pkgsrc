# $NetBSD: Makefile,v 1.1 2012/12/17 01:09:17 khorben Exp $
#

DISTNAME=	sofia-sip-1.12.11
CATEGORIES=	devel net comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sofia-sip/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://sofia-sip.sourceforge.net/
COMMENT=	Open-source SIP User-Agent library

LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
