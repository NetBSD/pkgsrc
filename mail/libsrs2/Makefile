# $NetBSD: Makefile,v 1.1 2017/03/30 01:55:57 schmonz Exp $

DISTNAME=	libsrs2-1.0.18
CATEGORIES=	mail
MASTER_SITES=	http://www.libsrs2.org/srs/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.libsrs2.org/
COMMENT=	Implementation of the Sender Rewriting Scheme for SMTP forwarding
LICENSE=	gnu-gpl-v2 OR modified-bsd

CONFLICTS+=	p5-Mail-SRS-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
