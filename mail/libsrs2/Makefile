# $NetBSD: Makefile,v 1.3 2022/12/15 11:25:37 schmonz Exp $

DISTNAME=	libsrs2-1.0.18
CATEGORIES=	mail
MASTER_SITES=	https://www.libsrs2.org/srs/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://www.libsrs2.org/
COMMENT=	Implementation of the Sender Rewriting Scheme for SMTP forwarding
LICENSE=	gnu-gpl-v2 OR modified-bsd

CONFLICTS+=	p5-Mail-SRS-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# for instance, `ar cru libsrs2.a srs2.o sha1.o` sometimes gives
# "ar: sha1.o: No such file or directory" on NetBSD with cc -pipe
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
