# $NetBSD: Makefile,v 1.22 2005/09/30 12:31:28 wiz Exp $

DISTNAME=	gsl-1.7
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GNU:=gsl/}

MAINTAINER=	david@maxwell.net
HOMEPAGE=	http://www.gnu.org/software/gsl/gsl.html
COMMENT=	The GNU Scientific Library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		gsl-ref.info

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"

# At least gcc-3.3.5 failed to compile gsl-1.6/statistics/lag1.c
# with -mcpu=v9 on a solaris/sparc system.
.if (${OPSYS} == "SunOS") && (${MACHINE_ARCH} == "sparc") && (!empty(CC_VERSION:M*gcc*))
CFLAGS:=        ${CFLAGS:C/-mcpu=[^ \t]*//g}
.endif
