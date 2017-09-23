# $NetBSD: Makefile,v 1.2 2017/09/23 20:30:30 wiedi Exp $

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

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

pre-configure:
		set -e; cd ${WRKSRC}; \
		aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
