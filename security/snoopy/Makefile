# $NetBSD: Makefile,v 1.3 2019/09/09 09:28:40 nia Exp $

DISTNAME=	snoopy-2.1.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/pkgsrc/distfiles/
EXTRACT_SUFX=	.zip

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/a2o/snoopy
COMMENT=	Log every executed command to syslog
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/snoopy-snoopy-2.1.0
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoheader autoconf automake gmake

BUILDLINK_TRANSFORM+=	rm:-Werror

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

pre-configure:
		set -e; cd ${WRKSRC}; \
		aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
