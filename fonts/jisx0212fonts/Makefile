# $NetBSD: Makefile,v 1.5 2001/09/09 20:36:23 agc Exp $
# Based on FreeBSD Id: Makefile,v 1.6 1999/02/12 17:23:40 motoyuki Exp
#

DISTNAME=	jisx0212fonts-0.0
CATEGORIES=	fonts x11 japanese
MASTER_SITES=	ftp://ginkaku.kudpc.kyoto-u.ac.jp/fonts/ \
		ftp://ftp.jp.netbsd.org/pub/NetBSD-jp/tut-jp/fonts/ \
		http://www.freebsd.org/~itojun/distfiles/
DISTFILES=	${BDF14} ${BDF16} ${BDF24} ${BDF40}

MAINTAINER=	itojun@itojun.org
COMMENT=	X11 X0212-1990 font.  14, 16, 24 and 40 dots availble

USE_X11BASE=	yes
WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	${DISTFILES}
MAKE_ENV+=	DISTDIR=${DISTDIR} DISTFILES="${DISTFILES}"

BDF14=		jisksp14.bdf.gz
BDF16=		jisksp16-1990.bdf.Z
BDF24=		min-1-24.bdf.gz
BDF40=		jisksp40.bdf.Z

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@for file in ${EXTRACT_ONLY}; do \
		if ! (cd ${WRKDIR} && \
			${GUNZIP_CMD} -c < ${_DISTDIR}/$$file > `echo $$file | ${SED} -e 's/\.Z//' -e 's/\.gz//'`); then \
			exit 1; \
		fi; \
	done

.include "../../mk/bsd.pkg.mk"
